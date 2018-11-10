#Script para la generación de pulsos a partir de una frecuencia dada

import sys, csv
import pyfirmata
from time import sleep

hertz = 0
if len(sys.argv) > 1:
    hertz = int(sys.argv[1])
    print (hertz)
else:
    hertz = 1

port = "/dev/ttyUSB0"
board = pyfirmata.Arduino(port)

it = pyfirmata.util.Iterator(board)
it.start()

led = board.get_pin("d:13:o")
on = 0
print("Configurado")

while True:
      try:
          print (1/hertz)
          sleep(1/hertz)
          if on == 0:
              led.write(1)
              on = 1
              print("LedOn")
          else:
              led.write(0)
              on = 0
              print("LedOff")

      except KeyboardInterrupt:
          board.exit()
          break
