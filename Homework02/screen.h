#define _CRT_SECURE_NO_WARNINGS

/* 버퍼 초기화 함수 */
int clearBuffer(char* screenBuf, int width, int height);

/* 수업시간에 배운 x,y에 스트링을 쓰는 함수를 짜면 됨. */
int writeStringToBuffer(const char* string, int x, int y);
