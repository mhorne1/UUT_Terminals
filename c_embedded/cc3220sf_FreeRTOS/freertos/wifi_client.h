#ifndef WIFI_CLIENT_H_
#define WIFI_CLIENT_H_

#define DEST_IP_ADDR                SERVER_DEST_IP_ADDR
#define PORT                        SERVER_PORT
#define FRAME_LENGTH                SERVER_FRAME_LENGTH

#define NUM_OF_PKT                  (1)
#define ALWAYS_OPEN_SOCK            (-1)
#define OPEN_SOCK_ONCE              (-2)

typedef enum
{
    SocketType_UDP,
    SocketType_TCP,
    SocketType_SEC_TCP
}SocketTypes;

#define SOCKET_TYPE                 SocketType_TCP

typedef enum
{
    UseCase_Normal,
    UseCase_LSI,
    UseCase_IotLowPower
}AlwaysConnectedUseCases;

/* options-> UseCase_Normal, UseCase_LSI, UseCase_IotLowPower */
#define AC_USECASE                  UseCase_Normal

typedef enum
{
    UseCase_HIB,
    UseCase_LPDS,
    UseCase_Transceiver,
    UseCase_IntermittentlyConnected,
    UseCase_AlwaysConnected
}Power_UseCases;

/* options-> UseCase_HIB, UseCase_LPDS, UseCase_Transceiver,
UseCase_IntermittentlyConnected, UseCase_AlwaysConnected */
#define PM_USECASE                  UseCase_AlwaysConnected


typedef struct _PowerMeasure_AppData_t_
{   /* The exercised use case  */
    Power_UseCases                 useCase;
    /* The always connected use case  */
    AlwaysConnectedUseCases        alwaysConnectedUseCase;
    /* how many packet to transmit on each interval of this use case */
    uint32_t                       pktsToDo;
    /* socket ID*/
    int32_t                        sockID;
    /* Socket type */
    SocketTypes                    socketType;
    /* IP address */
    uint32_t                       ipAddr;
    /* socket port number */
    uint32_t                       port;
}PowerMeasure_AppData;

/* Control block definition */
typedef struct _PowerMeasure_ControlBlock_t_
{
    uint32_t        slStatus;    //SimpleLink Status
    mqd_t           queue;
    sem_t           sem;
    signed char     frameData[FRAME_LENGTH];
    SlSockAddrIn_t  ipV4Addr;
}PowerMeasure_ControlBlock;

//****************************************************************************
//                          FUNCTION PROTOTYPES
//****************************************************************************
void prepareDataFrame(uint16_t port,uint32_t ipAddr);
int32_t bsdTcpClient(uint16_t port, int16_t sid);

#endif /* WIFI_CLIENT_H_ */
