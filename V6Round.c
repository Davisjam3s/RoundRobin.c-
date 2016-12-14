#include <stdio.h>
struct rec /*This is for the structured array, this is so we can save 2 things in the same array slot*/
{
	char ProcessName; /*This will be the name for the array Process, this will be a letter that is defined*/
	int RunTime;	/* this will store a number for how long the process will take */
};

typedef struct rec Record; /*This is giving the structured array a name called Record this will allow me to define it later*/

main() {
	int choice; /*this is for selecting a choice*/
	int i; /*This is for the counter*/
	int CpuTimeOut =5; /* this is the time out time for the cpu*/
	Record a[6] = {0}; /* this is for the array it is also called a this will be sued when reading and wrting from the array also setting eveything to 0*/

	char Names = 65; /*Start at capital A*/
	

	system("clear"); /*This is to clear the screen so it does not clutter the page that you are looking at*/
	do 
	{	
		/*This will ask the user what options they would like */
		printf("\n"); /*Creates a line break to go to the next line*/
		printf("0- Enter Data items\n");/*This will ask the user enter data items when they press 1 and then press enter*/
		printf("1- Enter a single Data item\n");/*This is for setting a new Process this does not work if the array is currently full*/
		printf("2- Show the data items \n"); /*Pressing this will show the user the items they ahve eneterd*/
		printf("3- Step through the Process \n"); /*This will run the program 1 by one there is more comments for that*/
		printf("4- What is the CPU TimeOut Time\n"); /*This will show the user how long the cpu will run before it's timed out*/
		printf("5- To quit\n"); /*Pressing this will Termiinate */
		printf("Choose an Option\n"); /*This is to promt the user to choose an option */
		scanf("%d", &choice); /*This will scan the choice that the user has eneterd */

		/*Begining of choice 0*/
		if (choice == 0) /*If the user choose option one then this will run*/
		{
			system("clear"); /*Clear the console so it will look cleaner and not clutterd */
			for (i = 0; i <= 4; i++) /*Setting i to 0 and it has to be less then 4 which is 5 and eveytime it its looped i++ will add 1 to i*/
			{
				
				a[i].ProcessName = Names; /*Manually setting the name for the Process name, so it will say  A B C D or E*/
				Names++; /*Adding 1 to names to increase the value */
				printf("Enter Run Time for Process %c\n",a[i].ProcessName); /*Telling the user what to do, here it will say enter the run time for Process A B C D E*/
				scanf("%d", &a[i].RunTime); /*Wating for the user to enter a number, this will then be stored in the array with its name*/

				if (Names == 91) /*91 is a bracket, which is a symbol, I would like a Letter so we set it back to A what is 65*/
				{
					Names = 65; /*Setting it to A*/
				}

				
			}	
		}
		/*End of Choice 0 once this has finished it will go back to where it asks the user to enter a promt */
		/*start of option 1*/
		if (choice == 1)
		{
			system("clear"); /*Clear the console so it will look cleaner and not clutterd */
			int SingleRuntime; /*A new Varible to set the new run time */

			printf("Enter Run Time for a single  Process %c\n",Names); /*Telling the user what to do, here it will say enter the run time for Process A B C D E*/
			scanf("%d", &SingleRuntime); /*Wating for the user to enter a number, this will then be stored in the array with its name*/
			
			for (i = 0; i <=4;i++) /*setting i to 0 and then counting to 4 which is 5 and then adding 1 each time*/
			{
				if (a[i].RunTime == 0) /*it needs to to find the first part of the array where the run time is 0*/
				{
					a[i].ProcessName = Names; /*We need to give it a new name*/
					a[i].RunTime = SingleRuntime; /*we need to set the run time for it*/

					Names++; /*add 1 to Names which will increase the Letter so if it was A it will then change to b*/
					if (Names == 91) /*If Names = 91 then it means it s ( and I want letters not symboyls by so we set Names back to A*/
					{
						Names = 65; /*Setting the names back to a*/
					}
					break; /*Stop this from running */
				}

			}
			
		}
		/*End of option 1*/
		/*Begining of Choice 2*/
		if (choice == 2) /*when the user presses 2 then this will run */
		{
			system("clear"); /*Clearing the console to look tidy*/
			printf("Name of Process: Run Time: \n"); /*This will show the users what they have enterd With the name of the process and the run time for it*/
			for (i=0;i<=4;i++) /*again using i will do the counting untill we have retrived evything from the array*/
			{
				printf("%c %16d \n", a[i].ProcessName, a[i].RunTime); /*This is what it will show the user so example it might say A   5 this telling the user that A has the run time of 5*/
			}
		}
		/*End of Choice 2 when this is done it will ask the user what they would like to do again*/
		/*Start of Choice 3*/
		if (choice == 3) /*This is what will happen when the user presses 3*/
		{
			system("clear"); /*Clearing the console */
			int ans = a[0].RunTime - CpuTimeOut; /*creating an int called ans this will check to see if the process will need to run again, as the the cpu time out is 5*/
			/*because if a = 5 ans would be 0 and that proces will not need to run again, but if a=6 ans would be 1 meaning that a will need to run again*/
			
			if (ans<=0) /*if ans is less than 0 or equal to 0 then the process will not need to run again, this means that we can remove it from the array and move the next ones up*/
			{
				printf("The data number has been processed\n"); /*Telling the user that it has been processed it will then have to move the next parts of the array fowards*/
				a[0].ProcessName = a[1].ProcessName; /*It will move the name from array 1 to array 0*/
				a[0].RunTime = a[1].RunTime; /*it will move Runtime from array 1 to array 0*/ /*These are the same from the others*/
				a[1].ProcessName = a[2].ProcessName;
				a[1].RunTime = a[2].RunTime;
				a[2].ProcessName = a[3].ProcessName;
				a[2].RunTime = a[3].RunTime;
				a[3].ProcessName = a[4].ProcessName;
				a[3].RunTime = a[4].RunTime;
				a[4].ProcessName = 0; /*As we no longer need anything here then i can set this to 0*/
				a[4].RunTime =0; /*we dont need a run time if there is nothing */

				printf("Name of Process: Run Time: \n"); /*this is to show the user the new array that has been updated this uses the same code for option 2*/
				for (i=0;i<=4;i++)
				{
					printf("%c %16d \n", a[i].ProcessName, a[i].RunTime); 
				}
			}
			else /*now if ans equals more than 0 and had a longer run time than 5 it will then need to be moved to the back of the queue, this means that we need a way to move it to the back*/
			{
				system("clear"); /*Cleaning up the console */
				printf("The process has been timed out, it will now join the back of the queue\n"); /*Telling the user that it has worked but tells them that it has been put back to the end of the queue*/
				/*I have to create some varibles to hold the data as i move to the end of the queue */
				char CpuStoreProcessName = a[0].ProcessName; /*Holding the name*/
				int CpuStoreRuntime = ans; /*Holding the new run time*/

				

				a[0].ProcessName = a[1].ProcessName;
				a[0].RunTime = a[1].RunTime;
				a[1].ProcessName = a[2].ProcessName;
				a[1].RunTime = a[2].RunTime;
				a[2].ProcessName = a[3].ProcessName;
				a[2].RunTime = a[3].RunTime;
				a[3].ProcessName = a[4].ProcessName;
				a[3].RunTime = a[4].RunTime;
				a[4].ProcessName = 0; /*This will read from the varable to set the name back to its orginal form*/
				a[4].RunTime = 0; /*This will add the new run time to the array*/

				for (i = 0; i <=4;i++) /*This is a for loop, this loop will make sure it fills the array where it it is 0 so the top 0 will be chnaged to make sure that i dont have to wait behind emmty processes*/
				{
					if (a[i].RunTime == 0) /*Looing for where RunTime is = to 0*/
					{
						a[i].ProcessName = CpuStoreProcessName; /*It will then fill that part of the array with the varible */
						a[i].RunTime = CpuStoreRuntime; /*Setting the run time*/
						break; /*this break makes sure that it does not keep looping this, this is bevause it will then fill every 0 with these values */
					}

				}

				printf("Name of Process: Run Time: \n"); /*Again this will show the user the new order*/
				for (i=0;i<=4;i++)
				{
					printf("%c %16d \n", a[i].ProcessName, a[i].RunTime);
				}
			}
		}
		/*End of Choice 3*/

		/*Start of Choice 4*/
		/*This option will tell the user how long the process will last in the processor*/
		if (choice == 4) /*If the user enters 4 then*/
		{
			system("clear"); /*This will clear the screen*/
			printf("\nThe CPU will timeout after %d Seconds\n",CpuTimeOut); /*This will tell the user how long the CPU will process the Process 4*/
		}
		/*End of choice 4*/		

	} /*End of the do*/

	while (choice != 5); /*If the user choose 5 then this will terminate the program*/
	system("clear"); /*Clear the Page to reduce clutter*/
	printf("This is Quit\n"); /*Telling the user they have quit*/

	}