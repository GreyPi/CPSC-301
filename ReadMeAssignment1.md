# CPSC-301
Assignment1.cpp

To find the number of records in the text file I used a for loop with a string variable to read in how many lines are in the file.
I stroed the number of records into varible "N".
To store all the information from the text file I used a while loop to read in the file and then a for loop to read in 
the name and the balance into each indicie of "PERSON P[N]". 
I used strcpy and strcat to correctly store in the names with a space.
To display all the records I used a simple for loop of "P[i]".
To find the richest person in the file I used an If statement within a for loop that compared each indicie with a value called
"high" which started at 0. I then stored the name[i] assoicated with the highest value.
I then assigned the highest value to that indicie "i" of P[i].
After getting the highest value I then created fstream to read and out to the data.txt file.
I open the file one last time and output all the data with the updated record into data.txt.
I used <iomanip> to format the decimal places of the balance.
