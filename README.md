# Homework 02 - Guessing Game

Name: Aidan Schrier

Github Account name: Ari-Schrier

How many hours did it take you to complete this assignment (estimate)? About five hours.

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
- None


Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
- None


(Optional) What was your favorite part of the assignment? 

I found the process of writing tests without using a dedicating test system like we use in python or java to be really interesting.

(Optional) How would you improve the assignment? 

## Please responds to the following questions

1. In the *worst* case, how many guesses would our guessing game take to get the right answer if we had no hints at all?

Without hints, it would take ten guesses at most



2. In the *worst* case, how many guesses does it take to get the right number if we get a hint of "higher or lower" when guessing numbers 1-10 and guess intelligently (always picking in the middle of the remaining set of numbers)?
Hint: In your answer, show this mathematically with the [log function](https://www.mathsisfun.com/algebra/logarithms.html).

With a hint of higher or lower, it takes four guesses at most. I know this because by always guessing intelligently I can consistantly cut the number of possible options in half. After guess one I will be left with five options at most. After guess two I'll have a maximum of two options left. Guess three will leave me with one option at most, which I will get on guess four. Another way to look at this is that log2(10) equals 3.3, which I can round up to four guesses.


If you have questions about how to how to talk about this worst case, check out Chapter 1 of [Grokking Algorithms](https://www.oreilly.com/library/view/grokking-algorithms/9781617292231/).  (see the syllabus for how to log on to O'Reilly Online for free). You only need to read the first half of the chapter to understand the reason for the maximum number of guesses; the second half of the chapter is useful, but we won't talk about big O notation and running time until next week. 

## Important notes

* Your code **must compile and run** on the Khoury machines to earn credit. Make sure you test your programs on these machines, as this is where we grade your assignments.
* You must commit any additional files(if any) into your repository so we can test your code.
  * Points will be lost if you forget!
* Do not forget, once you have pushed your changes to your repo make sure that you **submit them to Gradescope before the assignment deadline!**

