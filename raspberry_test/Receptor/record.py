# Script para grabar de forma automática y convertir el video a formato de h264 a mp4
import sys, subprocess

file_name = "video"
time = 5.0
play = False

if (len(sys.argv)) > 1:
    for i in range(1,len(sys.argv)):
        if(sys.argv[i] == '-o'):
            file_name = sys.argv[i+1]
            i += 1
        elif(sys.argv[i] == '-t'):
            time = float(sys.argv[i+1])
            i += 1
        elif(sys.argv[i] == '-p'):
            play = True
        elif(sys.argv[i] == '-h'):
            print("[-t seconds] [-o output_file_name] [-p (Play after record)]")

print(file_name)
print(time)
print(play)

print(subprocess.check_output(['raspivid','-w','1280','-h','720','-fps','60','-t',str(int(round(time*1000))),'-o', 'prev_'+file_name+'.h264']))
print(subprocess.check_output(['rm','prev_'+file_name+'.h264']))
print(subprocess.check_output(['MP4Box','-fps','60','-add','prev_'+file_name+'.h264', file_name+'.mp4']))

if play is True:
    print(subprocess.check_output(['omxplayer','--fps','60',file_name+'.mp4']))
