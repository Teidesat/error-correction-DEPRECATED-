# Script para automatizar las pruebas para imagenes de alta exposición
import sys, subprocess

print(subprocess.check_output(['raspistill','-w','1280','-h','720','-ss','2000000','-o','long_exp.jpg']))
print(subprocess.check_output(['raspistill','-w','1280','-h','720','-o','normal_exp.jpg']))
