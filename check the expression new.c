#include<stdio.h>
int check_exp(char *s);
int main()
{
	char str[50];
	int result;
	printf("Enter the expression (do not put a space between the numbers of a multidigit operand): ");
	scanf("%s",str);
	result=check_exp(str);
	if(result==-1)
		printf("The expression is not valid");
	else
		printf("The expression is valid");
	return 0;
}
int check_exp(char *s)
{
	int leftb=0,rightb=0,operand=0,operatr=0,flag=0,space=0;
	while(*s!='\0')
	{
	    if(*s==' ')
            space=1;
        else
            space=0;
		if(*s=='(')
			leftb++;
		else if(*s==')')
			rightb++;
        //flag=0 means it's an operator flag=1 means it's an operand
        else if(*s=='+'||*s=='-'||*s=='*'||*s=='/'||*s=='%'||*s=='^')
        {
            //two operand cannot occur one after another
            if(flag==0)
                return -1;
            flag=0;
            operatr++;
        }
        else
        {

            //two operator cannot occur one after another in infix expression
            //but if the operand is not of single digit like if 25 + 30 then 2 and 5 occur one after another but there is no space(space=0)
            if(flag==1 && space==1)
                return -1;

            if((flag==0&&space==0))
            operand++;
            flag=1;

        }
        s++;
	}

	//the no of left bracket must be equal to no of right bracket
	if(leftb!=rightb)
	break;
        return -1;
    //the no of operands are always 1 more than operator like a+b-c operand=3,operator=2
    if(operatr!=(operand-1))
        return -1;
    return 2;
}
