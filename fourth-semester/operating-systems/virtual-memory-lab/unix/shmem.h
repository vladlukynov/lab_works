#define MAXBUFF 80
#define PERM 0666

//Структура данных в разделяемой памяти
typedef struct mem_msg
{
    char buff[MAXBUFF];
} Message;

// Ожидание уведомления от клиента
static struct sembuf wait_client_notify[1] = {2, -1, 0};

// Ожидание освобождения и блокировка разделяемой памяти
static struct sembuf mem_wait_lock[2] = {
    0, 0, 0,
    0, 1, 0};

// Освобождение памяти
static struct sembuf mem_unlock[1] = {0, -1, 0};

// Уведомляем клиента
static struct sembuf notify_client[1] = {3, 1, 0};

// Уведомление сервера о том, что клиент начал работу
static struct sembuf notify_server[1] = {2, 1, 0};

// Ждем завершения работы других клиентов и блокируем ресурс
static struct sembuf client_wait_lock[2] = {
    1, 0, 0,
    1, 1, 0};

// Освобождаем ресурс для возможности работы других клиентов
static struct sembuf client_unlock[1] = {1, -1, 0};

// Ожидание уведомления от сервера
static struct sembuf wait_server_notify[1] = {3, -1, 0};
