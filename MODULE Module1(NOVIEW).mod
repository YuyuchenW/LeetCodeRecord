MODULE Module1(NOVIEW)

    VAR socketdev server_socket;
    VAR socketdev client_socket;
    VAR string receive_string;
    VAR string client_ip;
    VAR rawbytes raw_data_send;
    VAR rawbytes raw_data_receive;
    VAR jointtarget joints;
    VAR num jointdata;

    PROC main()
    sockeetBuild;!Building a socket communication
    WHILE TRUE DO
    dataPack;!Package axis data into byte stream
    dataexchange;!Send data stream
    ENDWHILE
    ERROR
        IF ERRNO=ERR_SOCK_TIMEOUT THEN
            ResetRetryCount;
            RETRY;

        ELSEIF ERRNO=ERR_SOCK_CLOSED THEN
            SocketClose socketClient;
            SocketClose socketServer;
            WaitTime 3;
            ServerCreateAndConnect "127.0.0.1", 1025;
            ResetRetryCount;
            RETRY;
        ELSE
            TPWrite "ERRNO = "\Num:=ERRNO;
            SocketClose socketClient;
            SocketClose socketServer;
            ResetRetryCount;
            main;
        ENDIF
        SocketClose socketClient;
        SocketClose socketServer;
    
    ENDPROC
    
    PROC sockeetBuild()
    SocketCreate server_socket;
    SocketBind server_socket, "127.0.0.1", 1025;
    SocketListen server_socket;

            WHILE SocketGetStatus(socketClient)<>SOCKET_CONNECTED DO
            SocketAccept server_socket,client_socket\ClientAddress:=clientIP\Time:=WAIT_MAX;
            IF SocketGetStatus(socketClient)<>SOCKET_CONNECTED THEN
                TPWrite "LOGGER: Problem serving an incomming connection.";
                TPWrite "LOGGER: Try reconnecting.";
            ENDIF
            !Wait 0.5 seconds for the next reconnection
            WaitTime 0.5;
        ENDWHILE
    ENDPROC
    

    PROC dataexchange()
    !If you do not want to receive external data,you should comment out the line below,otherwise the thread will be blocked here
    !SocketReceive client_socket \rawData := raw_data_receive;
    WaitTime 0.01;
    SocketSend client_socket \rawData:=raw_data_send;
    ENDPROC
    
    PROC dataPack()
    joints := CJointT();
    ClearRawBytes raw_data_send;
    !Pack the six axis angles in order into the byte stream
    jointdata:=joints.robax.rax_1;
    PackRawBytes jointdata, raw_data_send\Network, (RawBytesLen(raw_data_send)+1)\Float4;
    jointdata:=joints.robax.rax_2;
    PackRawBytes jointdata, raw_data_send\Network, (RawBytesLen(raw_data_send)+1)\Float4;
    jointdata:=joints.robax.rax_3;
    PackRawBytes jointdata, raw_data_send\Network, (RawBytesLen(raw_data_send)+1)\Float4;
    jointdata:=joints.robax.rax_4;
    PackRawBytes jointdata, raw_data_send\Network, (RawBytesLen(raw_data_send)+1)\Float4;
    jointdata:=joints.robax.rax_5;
    PackRawBytes jointdata, raw_data_send\Network, (RawBytesLen(raw_data_send)+1)\Float4;
    jointdata:=joints.robax.rax_6;
