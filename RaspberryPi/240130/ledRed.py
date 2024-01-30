
import RPi.GPIO as GPIO
import time

led_red = 4
led_green = 5
led_blue = 6

GPIO.setmode(GPIO.BCM)

GPIO.setup(led_red, GPIO.OUT)
GPIO.setup(led_green, GPIO.OUT)
GPIO.setup(led_blue, GPIO.OUT)


try:
        while True:
                GPIO.output(led_red, True)
                time.sleep(0.01)
                GPIO.output(led_red, False)
                time.sleep(0.01)
		print("RED ON")
                GPIO.output(led_green, True)
                time.sleep(0.01)
                GPIO.output(led_green, False)
                time.sleep(0.01)
		print("GREEN ON")
                GPIO.output(led_blue, True)
                time.sleep(0.01)
                GPIO.output(led_blue, False)
                time.sleep(0.01)
		print("BLUE ON")
except KeyboardInterrupt:
        pass
GPIO.cleanup()
