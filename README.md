# MultithreadingCppWithCSVData
Budowanie wielowątkowej aplikacji w celu stworzenia bardziej zaawansowanego projektu c++ do portfolio, zgodnie z zaleceniami rekrutacyjnymi odnośnie ćwiczenia praktycznego języka c++ po ukończeniu akademii programistycznej. Zawsze musi być ambitnie, a wątki idealnie się w to wpisują w moim postrzeganiu ich poziomu ;)  TBC ... :) 

ACTUALLY OUTPUT: 

DEBUG MSG: Threads: 8
DEBUG MSG: Main thread id: 1
Processing (reading data) time: 0.332001 s

urlCreator is me!
Processing (creating URLs) time: 0.022002 s

videosRatings is me!
1000 likes added to video: aE4XqQZLkek
Likes was increase from: 4 to: 1004
Thank you for a successful transaction!
Processing (creating ratings) time: 0.019995 s

urlCreator is me!
videosRatings is me!

urlCreator is me!
videosRatings is me!

Processing (NORMAL) time: 0.041997 s
Processing (ASYNC) time: 0.031001 s
Processing (MULTI) time: 0.025002 s
2 THREADs ASYNC WAS FASTER THAN 1 ABOUT: 0.010996 s
2 THREADs MULTI WAS FASTER THAN 1 ABOUT: 0.016995 s
ASYNC (1) vs MULTI (2): 0.005999

CLUE - async threads should be faster if we got 'tasks-type' construction. Default multithread should be faster if we got 'workers-type' construction. 
CLUE 2 - there are still too less operations to compare effective works (data.csv got about 80k records). Working to add new functionality. 
