#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void ColorSet(int backColor, int textColor) //함수 선언 및 정의
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (backColor << 4) + textColor);
}

typedef enum ColorKinds
{
    black,
    blue,
    green,
    skyBlue,
    red,
    pink,
    Orange,
    white,
    gray,
    lightBlue,
    sky,
    brightGreen,
    brightpink,
    brightyellow,
    brighwhite,
} ColorKinds;

int main(void)
{
    int choice[4] = { 0, 0, 0, 0 }; //0.첫 메뉴 선택 1.실행메뉴 선택 2.단위변환(단위선택) 3.동물 다섯고개(힌트선택)
    int input[6] = { 0, 0, 0, 0, 0, 0 }; //0.구구단(단수) 1.UP & DOWN(추측값) 2.계산기(첫번째수) 3.계산기(두번째 수) 4.단위변환 5.동물 다섯고개(추측값)
    int re; //구구단 반복실행, 계산기 반복실행, #프로그램 반복실행
    int i; //프로그램종료, 구구단, UP & DOWN, 계산기
    int sum = 0; //계산기
    int result = 0; //구구단, 계산기
    double unit; //단위변환
    double input_°C; //단위변환
    double input_°F; //단위변환
    double star; //별의 연주시차
    double distance; //별 까지의 거리
    char operator; /*연산자*/ //계산기
    srand(time(NULL)); /*랜덤 함수에 시드값 생성*/ // 퀴즈, UP & DOWN, 동물 다섯고개
    int random = 0;
    ColorKinds colorkinds; //열거형 선언

    while (1) //프로그램 전체 무한반복
    {

        do
        {
            system("cls");
            printf("각 항목에 맞는 번호를 입력하여주세요\n\n");
            printf(" ***********\n");
            printf(" * 1. 실행 *\n");
            printf(" * 2. 옵션 *\n");
            printf(" * 3. 종료 *\n");
            printf(" ***********\n\n>>> ");
            scanf_s("%d", &choice[0]); //첫 메뉴선택 입력

        } while ((choice[0] < 1) || (choice[0] > 3)); //지정된 범위를 넘어가면 다시 출력

    switch (choice[0]) //첫 메뉴선택 1.실행 2.옵션 3.종료
    {
    case 1: //실행

        do
        {
            system("cls");
            printf("각 항목에 맞는 번호를 입력하여주세요\n\n");
            printf(" ***********************\n");
            printf(" * 1. 구구단 퀴즈 *\n");
            printf(" * 2. UP & DOWN *\n");
            printf(" * 3. 계산기 *\n");
            printf(" * 4. 단위 변환기 *\n");
            printf(" * 5. 별의 거리구하기 *\n");
            printf(" * 6. 동물 다섯고개 *\n");
            printf(" ***********************\n");
            printf("\n>>> ");
            scanf_s("%d", &choice[1]); //실행메뉴 선택 입력
        } while ((choice[1] < 1) || (choice[1] > 6)); //지정된 범위를 넘어가면다시 출력

        break;
            
    case 2: //옵션
        system("cls");
        ColorSet(black, Orange); //글자 색 변경(주황색)
            
        printf("개발자: 문태서\n");
        printf("개발완료: 2021.10.27\n");
        printf("__________________________\n");
        printf("각 항목에 대한 설명\n");
        printf("1. 구구단: 사용자가 입력한 양의 정수에 1부터 9까지 곱해서출력합니다.\n");
        printf("2. UP & DOWN: 1~100 사이의 랜덤한 함수를 정하고 사용자가 추측한 값과 비교함니다.\n");
        printf("3. 계산기: 사용자로부터 연산식을 입력받아 계산하고 그 값을 출력합니다.\n");
        printf("4. 단위 계산기: 변환할 여러 단위를 선택하고 숫자를 입력받아 다른 단위로 변환하여 출력합니다.\n");
        printf("5. 별의 거리구하기: 사용자로부터 별까지의 연주시차를 입력받아 별까지의 거리를 구한다음 출력합니다. (중학교 3학년 교육과정)\n");
        printf("6. 동물 다섯고개: 6가지 동물중 랜덤으로 한 동물을 정한다음 동물에따라 다른 다섯가지의 힌트와 보기를 출력\n");

        ColorSet(black, white); //글자 색 변경(하얀색)
        Sleep(2000);
        break;
            
    case 3: //프로그램 종료
        Sleep(1000);
        system("cls");
        ColorSet(white, red); //배경, 글자 색 변경(하얀색, 빨간색)

        for (i = 5; i > 0; i--)
        {
            printf("# %d초 뒤 프로그램이 종료됩니다.\n", i);
            Sleep(500);
        }
        ColorSet(black, white); //배경, 글자 색 변경(검은색, 하얀색)
        Sleep(1000);
        system("cls");
            
        return 0;
    }

    switch (choice[1]) //실행메뉴 선택 1.구구단 2.UP & DOWN 3.계산기 4.단위변환기 5.별의 거리구하기 6.동물 다섯고개
    {
    case 1: //1. 구구단
        do
        {
            system("cls");

            random = (rand() % 10) + 1; //1~10 사이의 랜덤함수 생성
            i = (rand() % 10) + 1; //i 변수에 1~10 사이의 랜덤값 저장
            printf("랜덤 구구단 문제가 출제됩니다.\n");
            printf("%d X %d =???\n\n>>> ", random, i);
            scanf_s("%d", &input[0]);
            result = random * i;
            if (result == input[0])
            {
                printf("정답입니다!!!\n");
            }
            else
            {
                printf("오답입니다 ᅲᅲ\n");
            }
            printf("____________________________\n");
            printf("0. 구구단 종료\n");
            printf("1. 구구단 반복실행\n\n>>> ");
                scanf_s("%d", &re); //구구단 반복실행 입력
        } while (re == 1); //re가 1일때 구구단 반복실행
            
        if (re == 0) //re가 0일때 구구단 종료
        {
            break;
        }

    case 2: //UP & DOWN
        system("cls");
        random = (rand() % 100) + 1; //1~100 사이의 랜덤함수 생성
        printf("1~100 사이의 난수가 생성되었습니다.");
            
        i = 0; //시도회수 초기화
        do
        {
            i++; //시도횟수 증가

            printf("정답을 추측하여보세요\n>>> ");
            scanf_s("%d", &input[1]); //추측값
            if (input[1] == random)
            {
                printf("\n정답입니다!!! / 시도횟수: %d번\n", i);
                Sleep(3000);
            }
            else if (input[1] < random)
            {
                printf("UP!!\n");
                printf("___________________________\n\n");
            }
            else if (input[1] > random)
            {
                printf("DOWN!!\n");
                printf("___________________________\n\n");
            }
        } while (input[1] != random);

        break;
            
    case 3: //계산기
        do
        {
            system("cls");
            printf("\n지원 연산자: +(더하기) -(빼기) *(곱하기) %(나머지 구하기) ^(제곱)\n\n");
            printf("간단한 연산식을 입력해주세요 [[ 정수 <연산자> 정수 ]] 의 형식 **연산자에 주의해주세요**\n\n>>> ");
            scanf("%d%c%d", &input[2], &operator, &input[3]); //첫번쨰 숫자, 연산자, 두번째 숫자

            if (operator == '+') //더하기 연산일 때

            {
                result = input[2] + input[3];
                printf("%d %c %d = %d 입니다.\n", input[2],operator, input[3], result);
            }
            else if (operator == '-') //뺴기 연산일 때
            {
                result = input[2] - input[3];
                printf("%d %c %d = %d 입니다.\n", input[2],operator, input[3], result);
            }
            else if (operator == '*') //곱하기 연산일 때
            {
                result = input[2] * input[3];
                printf("%d %c %d = %d 입니다.\n", input[2],operator, input[3], result);
            }
            else if (operator == '/') //나누기 연산일 떼
            {
                result = input[2] / input[3];
                printf("%d %c %d = %d 입니다.\n", input[2],operator, input[3], result);
            }
            else if (operator == '%') //나머지를 구할 때
            {
                result = input[2] % input[3];
                printf("%d %c %d = %d 입니다.\n", input[2],operator, input[3], result);
            }
            else if (operator == '^') //제곱 연산일 때
            {
                result = pow((double)input[2], input[3]);
                printf("%d %c %d = %d 입니다.\n", input[2],operator, input[3], result);

            }
            else
            {
                printf("지원하지 않는 연산자입니다.\n");
            }

            Sleep(1000);
            printf("____________________________\n");
            printf("0. 계산기 종료\n");
            printf("1. 더 계산하기\n\n>>> ");
            scanf_s("%d", &re); //계산기 반복선택 입력

        } while (re == 1); //re가 1일 경우 계산기 반복실행
            
        if (re == 0) //re가 0일 경우 계산기 종료
        {
            break;
        }
            
    case 4: //단위변환
        do
        {
        system("cls");
        printf(" #변환할 단위를 입력해주세요#\n\n");
        printf(" *****************************\n");
        printf(" * 1.mm 2.cm 3.m 4.km * \n");
        printf(" * 5.mg 6.g 7.kg *\n");
        printf(" * 8.°C 9.°F *\n");
        printf(" *****************************\n\n>>> ");
        scanf_s("%d", &choice[2]); //단위선택 입력
        } while ((choice[2] < 1) || (choice[2] > 9)); //지정된 범위를 넘어가면다시 출력

        break;
            
    case 5: //별의 거리구하기
        do
        {
            system("cls");
            printf("별의 연주시차를 입력해주세요 (초) \n\n>>> ");

            scanf_s("%lf", &star);
            distance = star / (star * star);
            printf("연주시차가 %lf인 별까지의 거리는 %lf pc(파섹) 입

            니다.\n", star, distance);

            Sleep(1000);
            printf("____________________________\n");
            printf("0. 별의 거리구하기 종료\n");
            printf("1. 더 계산하기\n\n>>> ");
            scanf_s("%d", &re); //'별의 거리구하기' 반복선택 입력
        } while (re == 1); //re가 0일때 '별의 거리구하기' 반복
                   
        if (re == 0) //re가 0일때 '별의 거리구하기' 종료
        {
            break;
        }

    case 6: //동물 다섯고개
        system("cls");
        random = (rand() % 5) + 1; //1~5 사이의 랜덤함수 생성
                   
        if (random == 1) //토끼
        {
            printf("이 동물은 귀가 큽니다.\n");
            printf("이 동물은 당근을 좋아합니다.\n");
            printf("이 동물은 초식동물입니다.\n");
            printf("이 동물은 이가 큽니다.\n");
            printf("이 동물은 눈이 빨갑니다.\n");
            }
        else if (random == 2) //하마
        {
            printf("이 동물은 무리를 지어 살아갑니다.\n");
            printf("이 동물은 발가락이 4개 입니다.\n");
            printf("이 동물은 몸에 털이 거의 없습니다.\n");
            printf("이 동물은 포유류입니다.\n");
            printf("이 동물은 몸집이 사람보다 거대합니다.\n");
        }
        else if (random == 3) //고래
        {
            printf("이 동물은 수중생활을 합니다\n");
            printf("이 동물은 물을 뿜을 수 있습니다.\n");
            printf("이 동물은 몸집이 사람보다 거대합니다.\n");
            printf("꼬리지느러미가 있습니다.\n");
            printf("이 동물은 전 세계에 약 100여종이 있습니다.\n");
        }
        else if (random == 4) //말
        {
            printf("이 동물은 다리가 4개 입니다.\n");
            printf("이 동물은 빨리 달릴 수 있습니다.\n");
            printf("이 동물은 사람들의 이동수단으로도 이용되었습니다.\n");
            printf("이 동물은 몸집이 사람보다 큽니다.\n");
            printf("이 동물은 초식동물입니다.\n");
        }
        else if (random == 5) //강아지
        {
            printf("이 동물은 다리가 4개 입니다.\n");
            printf("이 동물은 반려동물로 인기가 많습니다.\n");
            printf("이 동물은 사람을 잘 따릅니다.\n");
            printf("이 동물은 몸집이 사람보다 작습니다.\n");
            printf("이 동물은 털이 많습니다.\n");
        }
        Sleep(1500);
                   
        printf("_______________________________\n\n");
        printf("1. 힌트 더 듣기\n");
        printf("2. 정답 추론하기\n");
        scanf_s("%d", &choice[3]); //(힌트선택)
        break;
    }

    switch (choice[2]) //단위변환 선택 1.mm변환 2.cm변환 3.m변환 4.km변환5.mg변환 6.g변환 7.kg변환 8.°C 변환 9.°F 변환
    {
    case 1: //mm 변환
        system("cls");
        printf("단위를 제외한 숫자를 입력해주세요 (mm)\n\n>>> ");
        scanf_s("%d", &input[4]);
        unit = input[4] / 10.0; //mm-cm
        printf("%d mm = %lf cm\n", input[4], unit);
        unit = input[4] / 1000.0; //mm-m
        printf("%d mm = %lf m\n", input[4], unit);
        unit = input[4] / 1000000.0; //mm-km
        printf("%d mm = %lf km\n", input[4], unit);
        Sleep(2000);
        break;
                    
    case 2: //cm 변환
        system("cls");
        printf("단위를 제외한 숫자를 입력해주세요 (cm) \n\n>>> ");
        scanf_s("%d", &input[4]);
        unit = input[4] * 10.0; //cm-mm
        printf("%d cm = %lf mm\n", input[4], unit);
        unit = input[4] / 100.0; //cm-m
        printf("%d cm = %lf m\n", input[4], unit);
        unit = input[4] / 100000.0; //cm-km
        printf("%d cm = %lf km\n", input[4], unit);
        Sleep(2000);
        break;
                    
    case 3: //m 변환
        system("cls");
        printf("단위를 제외한 숫자를 입력해주세요 (m) \n\n>>> ");
        scanf_s("%d", &input[4]);
        unit = input[4] * 1000.0; //m-mm
        printf("%d m = %lf mm\n", input[4], unit);
        unit = input[4] * 100.0; //m-cm
        printf("%d m = %lf cm\n", input[4], unit);
        unit = input[4] / 1000.0; //m-km
        printf("%d m = %lf km\n", input[4], unit);
        Sleep(2000);
        break;
                    
    case 4: //km 변환
        system("cls");
        printf("단위를 제외한 숫자를 입력해주세요 (km) \n\n>>> ");
        scanf_s("%d", &input[4]);
        unit = input[4] * 1000000.0; //km-mm
        printf("%d km = %lf mm\n", input[4], unit);
        unit = input[4] * 100000.0; //km-cm
        printf("%d km = %lf cm\n", input[4], unit);
        unit = input[4] * 1000.0; //km-m
        printf("%d km = %lf m\n", input[4], unit);
        Sleep(2000);
        break;
                    
    case 5: //mg 변환
        system("cls");
        printf("단위를 제외한 숫자를 입력해주세요 (mg) \n\n>>> ");
        scanf_s("%d", &input[4]);
        unit = input[4] / 1000.0; //mg-g
        printf("%d mg = %lf g\n", input[4], unit);
                    
        unit = input[4] / 1000000.0; //mg-kg
        printf("%d mg = %lf kg\n", input[4], unit);
        Sleep(2000);
        break;
                    
    case 6: //g 변환
        system("cls");
        printf("단위를 제외한 숫자를 입력해주세요 (g) \n\n>>> ");
        scanf_s("%d", &input[4]);
        unit = input[4] * 1000.0; //g-mg
        printf("%d g = %lf mg\n", input[4], unit);
        unit = input[4] / 1000.0; //g-kg
        printf("%d g = %lf kg\n", input[4], unit);
        Sleep(2000);
        break;
                    
    case 7: //kg 변환
        system("cls");
        printf("단위를 제외한 숫자를 입력해주세요 (kg) \n\n>>> ");
        scanf_s("%d", &input[4]);
        unit = input[4] * 1000000.0; //kg-mg
        printf("%d kg = %lf mg\n", input[4], unit);
        unit = input[4] * 1000.0; //kg-g
        printf("%d kg = %lf g\n", input[4], unit);
        Sleep(2000);
        break;
                    
    case 8: //°C 변환
        system("cls");
                        
        printf("단위를 제외한 숫자를 입력해주세요 (°C) \n\n>>> ");
        scanf_s("%lf", &input_°C);
        unit = input_°C * 1.8 + 32; //°C-°F
        printf("%lf °C = %lf °F", input_°C, unit);
        choice[2] = 0;
        Sleep(2000);
        break;
                        
    case 9: //°F 변환
        system("cls");
        printf("단위를 제외한 숫자를 입력해주세요 (°F) \n\n>>> ");
        scanf_s("%lf", &input_°F);
        unit = (input_°F - 32) / 1.8; //°F-°C
        printf("%lf °F = %lf °C", input_°F, unit);
        choice[2] = 0;
        Sleep(2000);
        break;
    }

    switch (choice[3]) //동물 다섯고개(힌트선택) 1.토끼 2.하마 3.고래 4.말 5.강아지
    {
    case 1:
        printf("마지막 결정적인 힌트는!!!!\n\n");
        Sleep(1000);
        system("cls");
        for (i = 5; i > 1; i--)
        {
            printf("%d초 뒤에 공개됩니다.\n", i);
            Sleep(500);
        }
        system("cls");
                    
        if (random == 1) //토끼
        {
            printf("이 동물의 초성은 'ᄐᄁ' 입니다.\n\n");
        }
        else if (random == 2) //하마
        {
            printf("이 동물의 초성은 'ᄒᄆ' 입니다.\n\n");
        }
        else if (random == 3) //고래
        {
            printf("이 동물의 초성은 'ᄀᄅ' 입니다.\n\n");
        }
        else if (random == 4) //말
        {
        printf("이 동물의 초성은 'ᄆ' 입니다.\n\n");
        }
        else if (random == 5) //강아지
        {
        printf("이 동물의 초성은 'ᄀᄋᄌ' 입니다.\n\n");
        }
        Sleep(1000);
        /*힌트를 선택하면 힌트를 출력하고 보기를 출력해야하기 때문에break가 없음*/
                    
    case 2:
        do
        {
            printf("<보기> 1.토끼 2.하마 3.고래 4.말 5.강아지\n\n");
            printf("당신의 선택은>>> ");
            scanf_s("%d", &input[5]);
            
            if (input[5] < 1 || input[5] > 5)
            {
                system("cls");
            }

        } while (input[5] < 1 || input[5] > 5); //input[5]가 범위를 벗어났을때 다시 출력

        if (random == input[5])
        {
            printf("정답입니다!!!\n");
        }
        else
        {
            printf("오답입니다 ᅲ.ᅲ\n");
        }
        break;
    }
        Sleep(1500);
        printf("\n\n___________________________________\n\n");
        printf("프로그램을 끝내시겠습니까\n\n");
        printf(" **********************\n");
        printf(" * 0. 프로그램끝내기 *\n");
        printf(" * 1. 처음부터 다시실행 *\n");
        printf(" **********************\n\n>>> ");
        scanf_s("%d", &re); //반복실행 입력
                   
        if (re == 0) //반복실행 - 프로그램종료
        {
            ColorSet(white, red); //배경, 글자 색 변경(하얀색, 빨간색)
                
            for (i = 5; i > 0; i--)
            {
                printf("# %d초 뒤 프로그램이 종료됩니다.\n", i);
                Sleep(500);
            }
            ColorSet(black, white); //배경, 글자 색 변경(검은색, 하얀색)
            Sleep(1000);
            system("cls");
                    
            return 0;
        }

        for (i = 0; i < 4; i++) //choice 배열 초기화
        {
                choice[i] = 0;
        }
        for (i = 0; i < 6; i++) //input 배열 초기화
        {
                input[i] = 0;
        }
                   
        random = 0;

    }
}
