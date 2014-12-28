# ejemplo de creacion de un piano; en este caso, vamos a mandar datos    #
#  a través del puerto serie por el USB                                  #
# Fecha: 28/12/2014                                                      #
# Autor: Booleanbite                                                     # 
########################################################################## 

import serial
import readchar
#mensaje inicial
print("Piano Arduino. Presiona las telcas A,S,D,F,G,H,J,K Para las notas o Esc para salir.")
arduino = serial.Serial('/dev/tty.usbmodem1421',9600) #se abre el puerto usb

while True:
	char = readchar.readchar()#leer un caracter del teclado
	if(char == '\x1b'): # si es la tecla Esc. se cierra el bucle y se sale del programa
	  break;
	arduino.write(bytearray(char,'ascii')) # se manda el dato por el usb
arduino.close()#se cierra el puerto serie
