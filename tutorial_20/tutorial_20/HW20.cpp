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
   int workHour;   //�ִ� �ٹ��ð�

   printf("* 1���ϰ��� �ٹ��ð��� �Է��Ͻÿ� : ");
   scanf("%d", &workHour);

   return workHour;
}

int calcGlossPay(int workHour) {
   int glossPay;
   
   int hourlyWage = 3000;   //�ñ�
   int overTimePay = 0;   //�ʰ� �ٹ�����(40�ð� ����:0��)
   double overTimePayRate = 0.5;   // �ʰ��ٹ� ����� 
   int workHourStandard = 40;   // �ʰ��ٹ� ���ؽð�

   if (workHour > workHourStandard)
      overTimePay = (workHour- workHourStandard) * hourlyWage * overTimePayRate;

   glossPay = hourlyWage * workHour + overTimePay;

   return glossPay;
}

int calcTax(int glossPay) {
   int base = 100000;   //�ҵ� ���� 100,000��
   double underRate = 0.15;   // �������� �ҵ濡 ���� 15% ����
   double overRate = 0.25;   // �����̻� �ҵ濡 ���� 20% ����

   if (glossPay <= base)
      return glossPay * underRate;

   return base * underRate + (glossPay - base) * overRate;
}

void printPay(int glossPay, int taxes, int netPay) {
   printf("#�Ѽ��� : %d��\n", glossPay);
   printf("#���� : %d��\n", taxes);
   printf("#�Ǽ��� : %d��\n", netPay);
}