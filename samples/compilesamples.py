#!/usr/bin/env python

##@file char2mozzi.py
#  @ingroup util
#	A script for converting raw 8 bit sound data files to wavetables for Mozzi.
#
#	Usage: 
#	>>>char2mozzi.py <infile outfile tablename samplerate>
#	
#	@param infile		The file to convert, RAW(headerless) Signed 8 bit PCM.
#	@param outfile	The file to save as output, a .h file containing a table for Mozzi.
#	@param tablename	The name to give the table of converted data in the new file.
#	@param samplerate	The samplerate the sound was recorded at.  Choose what make sense for you, if it's not a normal recorded sample.
#
#	@note Using Audacity to prepare raw sound files for converting:
#	
#	For generated waveforms like sine or sawtooth, set the project
#	rate to the size of the wavetable you wish to create, which must
#	be a power of two (eg. 8192), and set the selection format
#	(beneath the editing window) to samples. Then you can generate
#	and save 1 second of a waveform and it will fit your table
#	length.
#	
#	For a recorded audio sample, set the project rate to the
#	Mozzi AUDIO_RATE (16384 in the current version). 
#	Samples can be any length, as long as they fit in your Arduino.
#	
#	Save by exporting with the format set to "Other uncompressed formats",
#	"Header: RAW(headerless)" and "Encoding: Signed 8 bit PCM".
#	
#	Now use the file you just exported, as the "infile" to convert.
#	
#	@author Tim Barrass 2010-12
#	@fn char2mozzi

import sys, array, os, textwrap, random

#if len(sys.argv) != 5:
#        print ('Usage: char2mozzi.py <infile outfile tablename samplerate>')
#        sys.exit(1)

#[infile, outfile, tablename, samplerate] = sys.argv[1:]

def char2mozzi(infile, outfile, tablename, samplerate):
	fin = open(os.path.expanduser(infile), "rb")
	print ("opened " + infile)
	uint8_tstoread = os.path.getsize(os.path.expanduser(infile))
	##print uint8_tstoread
	valuesfromfile = array.array('b') # array of signed int8_t ints
	try:
		valuesfromfile.fromfile(fin, uint8_tstoread)
	finally:
		fin.close()
	
	values=valuesfromfile.tolist()
	fout = open(os.path.expanduser(outfile), "w")
	fout.write('#ifndef ' + tablename + '_H_' + '\n')
	fout.write('#define ' + tablename + '_H_' + '\n \n')
	fout.write('#if ARDUINO >= 100'+'\n')
	fout.write('#include "Arduino.h"'+'\n')
	fout.write('#else'+'\n')
	fout.write('#include "WProgram.h"'+'\n')
	fout.write('#endif'+'\n')   
	fout.write('#include <avr/pgmspace.h>'+'\n \n')
	fout.write('#define ' + tablename + '_NUM_CELLS '+ str(len(values))+'\n')
	fout.write('#define ' + tablename + '_SAMPLERATE '+ str(samplerate)+'\n \n')
	outstring = 'const int8_t __attribute__((section(".progmem.data"))) ' + tablename + '_DATA [] = {'
	try:
		for i in range(len(values)):
			## mega2560 boards won't upload if there is 33, 33, 33 in the array, so dither the 3rd 33 if there is one
			if (values[i] == 33) and (values[i+1] == 33) and (values[i+2] == 33):
				values[i+2] = random.choice([32, 34])
			outstring += str(values[i]) + ", "
	finally:
		outstring +=  "};"
		outstring = textwrap.fill(outstring, 80)
		fout.write(outstring)
		fout.write('\n\n#endif /* ' + tablename + '_H_ */\n')
		fout.close()
		print ("wrote " + outfile)

def process_folder():
        include_list = ''
        sample_defs = ''
        const_list = ''
        func_next = 'int sampleNext(int sound) {\nint nextOut;\nswitch(sound) {\n'
        func_start = 'void sampleStart(int sound) {\nswitch(sound) {\n'
        func_pitch = 'void samplePitch(int sound) {\nswitch(sound) {\n'
        i = 0
        for filename in os.listdir('prepared'):
                raw_name = os.path.splitext(filename)[0]
                include_list += '#include <samples/mattdrums/'+raw_name+'.h>\n'
                sample_defs += 'Sample <'+raw_name+'_NUM_CELLS, AUDIO_RATE> s_'+raw_name+'('+raw_name+'_DATA);\n'
                const_list += 'const byte S_'+raw_name.upper()+' = '+str(i)+';\n'
                func_next += 'case S_'+raw_name.upper()+':\n'
                func_next += 'nextOut = s_'+raw_name+'.next();\n'
                func_next += 'break;\n\n'
                func_start += 'case S_'+raw_name.upper()+':\n'
                func_start += 's_'+raw_name+'.start();\n'
                func_start += 'break;\n\n'
                func_pitch += 'case S_'+raw_name.upper()+':\n'
                func_pitch += 's_'+raw_name+'.setFreq(pitch * (float) '+raw_name+'_SAMPLERATE / (float) '+raw_name+'_NUM_CELLS);\n'
                func_pitch += 'break;\n\n'
                i+=1
                char2mozzi('prepared/' + filename, '../../libraries/Mozzi-1.0.2/samples/mattdrums/' + os.path.splitext(filename)[0] + '.h', os.path.splitext(filename)[0], 16384)
        func_next += 'default:\n'
        func_next += 'nextOut=0;\n'
        func_next += '}\n'
        func_next += 'return nextOut;\n'
        func_next += '}\n'
        func_start += '}\n}\n'
        func_pitch += '}\n}\n'
        print include_list
        print sample_defs
        print const_list
        print func_next
        print func_start
        print func_pitch

process_folder()
