#include <stdio.h>

int inputWeekWorkHour();
int calcGlossPay(int workHour);
int calcTax(int glossPay);
void printPay(int glossPay, int taxes, int netPay);

int main()
{
   int workHour;

   int glossPay;
   int taxes;
   int netPay;

   workHour = inputWeekWorkHour();
   glossPay = calcGlossPay(workHour);
   taxes = calcTax(glossPay);
   netPay = glossPay - taxes;

   printPay(glossPay, taxes, netPay);

   return 0;
}

int inputWeekWorkHour() {
   int workHour;   //주당 근무시간

   printf("* 1주일간의 근무시간을 입력하시오 : ");
   scanf("%d", &workHour);

   return workHour;
}

int calcGlossPay(int workHour) {
   int glossPay;
   
   int hourlyWage = 3000;   //시급
   int overTimePay = 0;   //초과 근무수당(40시간 이하:0원)
   double overTimePayRate = 0.5;   // 초과근무 수당률 
   int workHourStandard = 40;   // 초과근무 기준시간

   if (workHour > workHourStandard)
      overTimePay = (workHour- workHourStandard) * hourlyWage * overTimePayRate;

   glossPay = hourlyWage * workHour + overTimePay;

   return glossPay;
}

int calcTax(int glossPay) {
   int base = 100000;   //소득 기준 100,000원
   double underRate = 0.15;   // 기준이하 소득에 대해 15% 세금
   double overRate = 0.25;   // 기준이상 소득에 대해 20% 세금

   if (glossPay <= base)
      return glossPay * underRate;

   return base * underRate + (glossPay - base) * overRate;
}

void printPay(int glossPay, int taxes, int netPay) {
   printf("#총수입 : %d원\n", glossPay);
   printf("#세금 : %d원\n", taxes);
   printf("#실수입 : %d원\n", netPay);
}