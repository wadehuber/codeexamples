#! /usr/bin/python

import time

print("Starting cron job")
outfile = open("/home/student/220/csc220summer18/class14/outfile.txt", 'a')

outstr = time.strftime("%H:%M:%S") + "\n"
time.sleep(5)
outfile.write(outstr)
print("Finishing cron job")
