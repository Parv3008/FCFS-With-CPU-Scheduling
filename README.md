Note:<br>
AWT Average Waiting Time<br>
ATT Average Turnaround Time<br>
ART Average Response Time<br>
FCFS First Come First Serve<br>

<h3>Algorithm:</h3>
1.	Start the program.<br><br>
2.	Input the number of processes (n).<br><br>
3.	For each process (i = 1 to n): a. Input the arrival time of the process. b. Input the burst time of the process. c. Set the waiting time, turnaround time, and response time to 0.<br><br>
4.	Sort the processes based on their arrival times in ascending order (if not already sorted).<br><br>
5.	Initialize current_time to 0 (the current time in the CPU).<br><br>
6.	For each process (i = 1 to n): a. Calculate the waiting time for the process:<br><br>
•	waiting_time[i] = current_time - arrival_time[i]<br>
•	If the waiting time is negative, set it to 0 (process has not arrived yet). b. Calculate the turnaround time for the process:<br>
•	turnaround_time[i] = burst_time[i] + waiting_time[i] c. Calculate the response time for the process:<br>
•	response_time[i] = waiting_time[i] (for FCFS, response time is the same as waiting time). d. Increment the current_time by the burst time of the current process.<br><br>
7.	Calculate the total_waiting_time, total_turnaround_time, and total_response_time as the sum of the respective times of all processes.<br><br>
8.	Calculate the average_waiting_time, average_turnaround_time, and average_response_time:<br><br>
•	average_waiting_time = total_waiting_time / n<br>
•	average_turnaround_time = total_turnaround_time / n<br>
•	average_response_time = total_response_time / n<br><br>

9.	Print the results:<br><br>
•	Average Waiting Time: average_waiting_time<br>
•	Average Turnaround Time: average_turnaround_time<br>
•	Average Response Time: average_response_time<br><br>
10.	End the program.
