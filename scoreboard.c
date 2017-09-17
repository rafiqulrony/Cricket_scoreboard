

		 /*Code for making a COMPUTERISED CRICKET SCORE BOARD*/
#include<stdio.h>
#include<conio.h>
								/*For showing only a big "OUT" in output screen*/
void out()
{
printf("*******************************************************************************\n\n");
printf("\t##################    ##             ##    ####################\n");
printf("\t##              ##    ##             ##             ##\n");
printf("\t##              ##    ##             ##             ##\n");
printf("\t##              ##    ##             ##             ##\n");
printf("\t##              ##    ##             ##             ##\n");
printf("\t##              ##    ##             ##             ##\n");
printf("\t##              ##    ##             ##             ##\n");
printf("\t##              ##    ##             ##             ##\n");
printf("\t##              ##    ##             ##             ##\n");
printf("\t##              ##    ##             ##             ##\n");
printf("\t##              ##    ##             ##             ##\n");
printf("\t##              ##    ##             ##             ##\n");
printf("\t##              ##    ##             ##             ##\n");
printf("\t##              ##    ##             ##             ##\n");
printf("\t##################    #################             ##\n\n\n\n");
printf("*******************************************************************************");
}



void all(int ov,int p,int p1)
{
	char c;
	char strplnm1[10],strplnm2[10],strcnnm[3];
	int a=0,ex=0,run=0,wk=0,pl1=0,pl2=0;
	int ball=0,over=0,pl1b=0,pl2b=0;
	int s1=0,s2=0,f1=0,f2=0;

 								/*For showing only a big "CRICKET" in output screen*/

	printf("\n\n\n\n");
	printf("********************************************************************************\n");
	printf("\t  ########   ######  ###  ########   #   #  ######  #######\n");
	printf("\t  #      #   #   #    #   #      #   #  #   #          #\n");
	printf("\t  #          #  #     #   #          # #    #          #\n");
	printf("\t  #          ###      #   #          ##     ######     #\n");
	printf("\t  #      #   #  #     #   #      #   # #    #          #\n");
	printf("\t  ########   #   #   ###  ########   #  #   ######     #\n\n");
	printf("********************************************************************************");
	printf("\n\n\n\t\t\tPress any key............\n");


 	 getch();


	/*For entering names of country,1st Batsman & 2nd Batsman of batting team*/
	printf("\nEnter Country Name<press ENTER>Enter 1st batsman Name<press ENTER>Enter 2nd batsman Name<Press ENTER>:\n\n");
	scanf("%s%s%s",&strcnnm,&strplnm1,&strplnm2);
	printf("\t\t\tPress Enter..............\n");


	   for(;;)

		  {
			if(over==ov)
			break;
			else if(wk==10)
			break;

			fflush(stdin);
			scanf("%c",&c);
			switch(tolower(c)){
						//Total 6 cases

										/*For power play*/
						case 'p':
						p1=over;
						break;

									//If you want to input run made by 1st batsman
									//One input (the run)
									/*For 1st Batsman's individual runs & balls if he was on strike at the last ball*/

						case '1':
						fflush(stdin);
						scanf("%d",&a);
						run=run+a;/*For total run increment*/
						pl1=pl1+a;/*For 1st Batsman's individual run increment*/
						pl1b++;   /*For 1st Batsman's individual ball increment*/
						ball++;   /*For total ball increment*/
						if(a==6)
							{
							s1++; /*For 1st Batsman's SIX's increment*/
							}
						if(a==4)
							{
							f1++; /*For 1st Batsman's FOUR's increment*/
							}
						break;

									//If you want to input run made by 2nd batsman
									//One input (the run)
									/*Same for 2nd Batsman's individual runs & balls if he was on strike at the last ball*/

						case '2':
						fflush(stdin);
						scanf("%d",&a);
						run=run+a;
						pl2=pl2+a;
						pl2b++;
						ball++;
						if(a==6)
							{
							s2++;
							}
						if(a==4)
							{
							f2++;
							}
						break;

										/*For extra run*/
										//One input (the run)

						case 'e':
						fflush(stdin);
						scanf("%d",&a);
						run+=a; /*For total run increment*/
						ex=ex+a;/*For extra run increment*/
						break;

										//If you want to input a dot ball.
										//One input (which batsman played the ball?)
										/*For total ball increment if the last ball was a dot ball*/

						case 'b':
						ball=ball+1;
						printf("Which batsman has played the ball ?(Batsman 1 or 2)");
						scanf("%d",&a);
						if(a==1)
						  pl1b++;
						else if(a==2)
						  pl2b++;
						break;

										/*For wicket*/
										//Two inputs: who is out and who is coming?

						case 'w':
						out();
						wk++;

						printf(" Who is out(Batsman 1 or 2)?....");
						scanf("%d",&a);

						/*After that the ball when 1st batsman is out*/
						if(a==1)
							{
							pl1b++; /*For 1st Batsman's ball increment in which ball he is out*/
							ball++; /*For total ball increment in which ball 1st Batsman is out*/
							printf("%s :  [RUN : %d]  [BALL : %d]  [SIX : %d]  [FOUR : %d]\n",strplnm1,pl1,pl1b,s1,f1);
							printf("NEXT PLAYER NAME : ");
							strplnm1[10]=scanf("%s",&strplnm1);
							pl1=0;f1=0;s1=0;pl1=0;pl1b=0;
							}
						/*Same for after that ball when 2nd Batsman is out*/
						else if(a==2)
							{
							pl2b++;
							ball++;
							printf("%s : [RUN : %d]  [BALL : %d]  [SIX : %d]  [FOUR : %d]\n",strplnm2,pl2,pl2b,s2,f2);
							printf("NEXT PLAYER NAME : ");
							strplnm2[10]=scanf("%s",&strplnm2);
							pl2=0;f2=0;s2=0;pl2=0;pl2b=0;
							}
						break;


					} /*Switch-Case operation in function "all()" is finished here*/

					/*clrscr();*/


					/*For managing the ball with over in score board when a current over gets finished with 6 balls*/
					if(ball==6)
					{
						over++;
						ball=0;
					}


								/*For showing main score board*/



			printf("********************************************************************************");
			printf("********************************************************************************\n");
			printf("    [%.3s]                   # ----------------[%.10s]----------------------\n",strcnnm,strplnm1);
			printf("                            # [RUN : %d]  [BALL : %d]  [SIX : %d]  [FOUR : %d]\n",pl1,pl1b,s1,f1);
			printf(" [OVER      :%2d.%.1d]          # --------------------------------------------------",over,ball);
			printf("                            #\n");
			printf(" [EXTRA RUN : %3d]          #\n",ex);
			printf("                            #\n");
			printf(" [WICKET    : %3d]          #\n",wk);
			printf("                            # ----------------[%.10s]---------------------\n",strplnm2);
			printf(" [RUN       : %3d]          # [RUN : %d]  [BALL : %d]  [SIX : %d]  [FOUR : %d]\n",run,pl2,pl2b,s2,f2);
			printf("                            # --------------------------------------------------");
			if(over<p)
				printf(" [POW PLAY] :   P]          #\n\n");
			else if((p1+5)>over)
				printf(" [POW PLAY] :   P]          #\n\n");
			else if(p1==-6)
				printf("	          	    #\n\n");
			else
				printf(" [POW PLAY] :   0]          #\n\n");
			printf("********************************************************************************");
			printf("********************************************************************************\n");



		  }/*The infinite For loop is finished here*/


}/*The largest function "all()" in this program is finished here*/

                          void ONEDAY_MATCH()
	                        {
	                          all(50,10,0);
                        	}

                          void T20_MATCH()
	                        {
	                          all(20,6,0);
	                        }

                          void TEST_MATCH()
                         	{
                         	  all(450,0,-6);
                         	}
                          /*Description of the above 3 parameters:
                           * 1st(ov): the number of total overs to be played; that is 50 for ODI, 20 for T20 and 450 for test.
                           * 2nd(p):
                           * 	ODI: The number of overs for which the 1st powerplay is fixed that is 1st 10 overs.
                           * 	T20: The number of overs for which the powerplay is fixed that is 1st 6 overs.
                           * 	Test: Not applicable, since there is no powerplay in a test match.
                           * 3rd(p1):
                           * 	ODI: For the next two powerplays.
                           * 	T20: Not applicable, since there is only one powerplay in T20 match.
                           * 	Test: Not applicable, since there is no powerplay in a test match.
                           * */


			/*For showing the menu to select the game type*/

  void option()
  {

   char b; /*Local variable declaration*/

	printf("\tA.TEST MATCH\n\n");
	printf("\tB.ONEDAY MATCH\n\n");
	printf("\tC.T20 MATCH\n\n");
	printf("\tD.HELP\n\n");
	printf("\tE.EXIT\n\n");
	printf("\tSELECT OPTION BY PRESING A,B,C,D or E (Uppercase) <Press ENTER>\n\n\t");
	scanf("%c",&b);

	  switch(toupper(b))
	  {
		case 'A':
		TEST_MATCH();
		break;

		case 'B':
		ONEDAY_MATCH();
		break;

		case 'C':
		T20_MATCH();
		break;

		case 'D':
		printf("1.If you want to input a dot ball press b <Press ENTER> then input the batsman no.(1 or 2) <press ENTER>.\n");
		printf("2.If you want to input run made by 1st batsman press 1 <press ENTER> then input the run earned by him at that ball <press ENTER>.\n");
		printf("3.If you want to input run made by 2nd batsman press 2 <press ENTER> then input the run earned by him at that ball <press ENTER>.\n");
		printf("4.If you want to input extra run press e <press ENTER> then input the extra run <press ENTER>.\n");
		printf("5.If you want to input wicket of 1st batsman press w <Press ENTER> press 1<press ENTER> input name of next batsman <Press ENTER>.\n");
		printf("6.If you want to input wicket of 2nd batsman press w <Press ENTER> press 2<press ENTER> input name of next batsman <Press ENTER>.\n");
		printf("\n\n\t Press ENTER to return MAIN MENU............");
		getche();
		fflush(stdin);
		option();
		break;

		case 'E':
		printf("THANK YOU FOR EXECUTING OUR PROGRAM.......................\n\n");
		break;
		} /*The Switch-Case operation in function "option()" is finished here*/

  } /*The function "option()" is finished here*/





int main()
{
option();
return 0;
}

