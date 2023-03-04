#!/usr/bin/python3

# Laboratorio 5
# Alexa Carmona B91643
# Raquel Corrales B92378
# Reconocimiento de movimiento con machine learning

import serial
import sys

# Iniciar conexion serial
ser = serial.Serial(
	port="/dev/ttyACM0",
	baudrate=9600,
	parity=serial.PARITY_NONE,
	stopbits=serial.STOPBITS_ONE,
	bytesize=serial.EIGHTBITS,
	timeout=0
)

# Informacion
print("Conexion exitosa: " + ser.portstr)
line = []

# Nombre del archivo output
arch = sys.argv[1]

# Crear archivo output
f = open(arch, "w+")
f.write("aX, aY, aZ, gX, gY, gZ\n")

# Parsear la informacion serial
while True:
	for c in ser.read():
		c = chr(c)
		line.append(c)
		if c == "\n":
			print("Line: " + "".join(line))
			print(len(line))
			if len(line) >= 38 and len(line) <= 44:
				string = "".join(line)
				f.write(string)
			line=[]