#define _CRT_SECURE_NO_WARNINGS

/* ���� �ʱ�ȭ �Լ� */
int clearBuffer(char* screenBuf, int width, int height);

/* �����ð��� ��� x,y�� ��Ʈ���� ���� �Լ��� ¥�� ��. */
int writeStringToBuffer(const char* string, int x, int y);
