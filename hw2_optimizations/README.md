---3/22/2017 Update----
This is my first attempt at using openMP. I started with the program provided by Dr. Kalva. I added a while loop on line 203 in the main program. This causes the bmp conversion to be run 3 times to get the base running time above 30 seconds. I noticed that this loop causes the image to be produced incorrectly and would like to see if there is a way to remedy this.

I began by using Intel Parallel Studio to find and measure hotspots. I then used and incorporated their Guided Auto-Parallel (GAP) suggestions, which provided an increase in performance while maintaining photo integrity. The lines of GAP have been commented out.

I am trying to incorporate openMP into the loops on lines 75 and 76 in the yuv2bmp function, which performs the BMP conversion. As it is right now, the program runs on multiple cores but experiences a lot of time waiting and takes more time to finish compared to the code with GAP. I tried incorporating openMP into the inner loop on line 76 and found that it the program finished in a shorter amount of time, but the image was not produced correctly.

---3/29/2017 Update---
I removed the while loop that increased run time to 30 seconds. This allowed the image to be converted correctly and allowed me to check the output better.

--3/29/2017 'Parallel' Update---
I used the suggestions from the GAP remarks and applied them in the for loop in the main function and the for loops in the conversion function. This update has given me the fastest run time so far (~2.6 per the HPClock Timer and ~2.7s per the VTune analyzer). However, according to VTune, it still only uses one thread.