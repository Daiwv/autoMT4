/*----------------------------------------------------------------------*/

#include "Definitions.h"

#ifndef _MT4_TERM_COMM_H_
#define _MT4_TERM_COMM_H_

  #define MT4_TERM_COMM_LOCAL

	#ifdef MT4_TERM_COMM_LOCAL
		#define DLL_FUNC __declspec( dllexport )
	#else
		#define DLL_FUNC __declspec( dllimport )
	#endif

	typedef enum
	{
		MT4_RET_OK,
		MT4_RET_ERROR,
		MT4_RET_ALREADY_CONNECTED,
		MT4_RET_NOT_CONNECTED,
		MT4_RET_NO_CONNECTION,
		MT4_RET_TECH_PROBLEM,
		MT4_RET_OLD_VERSION,
		MT4_RET_NO_MARKET_SYMBOL,
		MT4_RET_SYMBOL_NOT_SUPPORTED,
		MT4_RET_TIMEOUT,
		MT4_RET_NOT_YET_READY,
		MT4_RET_TRADE_NOT_ALLOWED,
		MT4_RET_TRADE_DISABLED,
		MT4_RET_NOT_ENOUGH_RIGHTS,
		MT4_RET_TOO_FREQUENT_REQUESTS,
		MT4_RET_ACCOUNT_DISABLED,
		MT4_RET_MARKET_CLOSED,
		MT4_RET_NOT_ENOUGH_MONEY,
		MT4_RET_INVALID_TICKET,
		MT4_RET_INVALID_ACCOUNT,
		MT4_RET_INVALID_PRICE,
		MT4_RET_INVALID_STOPS,
		MT4_RET_INVALID_VOLUME,
		MT4_RET_PRICE_CHANGED,
		MT4_RET_OFF_QUOTES,
		MT4_RET_REQUOTE,
		MT4_RET_TRADE_CONTEXT_BUSY,
		MT4_RET_SYSTEM_BUSY,
		MT4_RET_SERVER_BUSY,
		MT4_RET_BROKER_BUSY

	} MT4_RET_CODE;

	typedef enum
	{
		MT4_PERIOD_M1	= 1,
		MT4_PERIOD_M5	= 5,
		MT4_PERIOD_M15	= 15,
		MT4_PERIOD_M30	= 30,
		MT4_PERIOD_H1	= 60,
		MT4_PERIOD_H4	= 240,
		MT4_PERIOD_D1	= 1440,
		MT4_PERIOD_W1	= 10080,
		MT4_PERIOD_MN1	= 43200

	} MT4_PERIOD;

	typedef enum
	{
		MT4_OP_TYPE_BUY			= 0,
		MT4_OP_TYPE_SELL		= 1,
		MT4_OP_TYPE_BUYLIMIT	= 2,
		MT4_OP_TYPE_SELLLIMIT	= 3,
		MT4_OP_TYPE_BUYSTOP		= 4,
		MT4_OP_TYPE_SELLSTOP	= 5

	} MT4_OP_TYPE;

	typedef struct 
	{
		int					AccountNumber;
		TCHAR				Name[ 64 ];
		double				Balance;
		double				Equity;
		double				Margin;
		double				FreeMargin;
		int					Leverage;
    bool       IsDemoAccount;
	} MT4AccountInfo;

	typedef struct
	{
		int       	SymbolId;
		BOOL				Present;
		double				Point;
		int					Spread;
		int					Lot;
		int					Stops;

    TCHAR				StringId[ 64 ];
    TCHAR				SymbolDescription[ 128 ];
    TCHAR				SymbolType[ 64 ];

	} MT4MarketSymbolInfo;

	typedef struct
	{
		time_t				Ctm;
		double				Open;
		double				Low;
		double				High;
		double				Close;
		unsigned int		Volume;

	} MT4RateInfo;

	typedef struct
	{
		int	           SymbolId;
		MT4_OP_TYPE			Command;
		double				Lots;

		double				Price;
		int					Slippage;

		double				StopLoss;
		double				TakeProfit;

		int					MagicNumber;

	} MT4SendOrderInfo;

	typedef struct
	{
		int					Ticket;

		int 	        SymbolId;
		MT4_OP_TYPE			Command;
		double				Lots;

		time_t				OpenTime;

		double				OpenPrice;
		double				StopLoss;
		double				TakeProfit;

		double				Profit;
		double				Swap;

		int					MagicNumber;

	} MT4OrderInfo;

	typedef struct
	{
		int					Ticket;

		int	         SymbolId;
		MT4_OP_TYPE			Command;
		double				Lots;

		time_t				OpenTime;
		time_t				CloseTime;

		double				OpenPrice;
		double				ClosePrice;

		double				StopLoss;
		double				TakeProfit;

		double				Profit;
		double				Swap;

		int					MagicNumber;

	} MT4ClosedOrderInfo;

  class SunkTCPClient;


  #define NO_LICENCE

#ifndef NO_LICENCE
  /// <summary>
  /// Activate your licence
  /// </summary>
  /// <param name="ipLogin">Your login on http://mt4api.pusku.com/ </param>
  /// <param name="ipPassword">Your pass from http://mt4api.pusku.com/ .</param>
  /// <param name="oMessage"> Error description if call failed</param>
  DLL_FUNC  bool  __stdcall MT4_TC_Licence_Autorize(const char* ipLogin, const char* ipPassword, char* oMessage);
#endif


  /// <summary>
  /// Try connect to MT4_API.ex 
  /// </summary>
  /// <param name="ipAddress"> ip addres of mashine where running MetaTrader4 with MT4_API.ex for local mashine use "127.0.0.1" </param>
  /// <param name="iPort"> port where hosted MT4_API.ex (you specify it at lanch of MT4_API.ex) </param>
  /// <param name="oErrorMessageBuffer_255"> buffer where will be writed error description if functiuon call failed. </param>
  /// <param name="iLoggerName  "> Name of file for log. </param>
  DLL_FUNC SunkTCPClient* __stdcall MT4_TC_StartClient(const char* ipAddress, int iPort, char* oErrorMessageBuffer_255, const TCHAR * iLoggerName = NULL);


  /// <summary>
  ///  Destroy clien instance of MT4_API.ex 
  /// </summary>
  DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_StopClient(SunkTCPClient* ipClient);

  /// <summary>
  /// Get info about current account logged in
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="ipTagetInstance"> pointer to some allocated instance of MT4AccountInfo where data will be writed. </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_GetAccountInfo(SunkTCPClient* ipClient, MT4AccountInfo* ipTagetInstance);

  
  /// <summary>
  /// Get count of sybols avalable in current MT4 terminal instance
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="oCount"> pointer to some allocated instance of int where data will be writed. </param>
  DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_GetSymbolListCount(SunkTCPClient* ipClient, int* oCount);

  /// <summary>
  /// Get info about symbol with specified Id. Id can be from [0 to MT4_TC_GetSymbolListCount)
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="ipTagetInstance"> pointer to some allocated instance of MT4AccountInfo where data will be writed. </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_GetMarketSymbolInfo(SunkTCPClient* ipClient, int iSymbolId, MT4MarketSymbolInfo* ipTagetInstance);

  /// <summary>
  /// Lanch history loading to MT4 Terminal
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="iSymbolID"> id of symbol to load  </param>
  /// <param name="iPeriodId"> id of period to load </param>
  /// <param name="iStartDate "> time from data should be load  </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_LaunchHistoryLoading(SunkTCPClient* ipClient, int iSymbolID , MT4_PERIOD iPeriodId, time_t iStartDate);

  /// <summary>
  /// Block thread while data loading 
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="iSymbolID"> id of symbol to load  </param>
  /// <param name="iPeriodId"> id of period to load </param>
  /// <param name="oDataFrom"> when load finished, return first date from data recived. It can be differend from data called MT4_TC_LaunchHistoryLoading due to to long period requested. </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_WaitHistoryLoading(SunkTCPClient* ipClient, int iSymbolID , MT4_PERIOD iPeriodId, time_t* oDataFrom);

  /// <summary>
  /// Get loaded data
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="iSymbolID"> id of symbol to load  </param>
  /// <param name="iPeriodId"> id of period to load </param>
  /// <param name="opCandles"> pointer to allocated array of MT4RateInfo items to write recived data.  </param>
  /// <param name="ioSize"> put here size of opCandles array. After call it return count of MT4RateInfo elements writed to opCandles. </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_GetHistory(SunkTCPClient* ipClient, int iSymbolID, MT4_PERIOD iPeriodId, MT4RateInfo* opCandles, int* ioSize);

  /// <summary>
  /// Get bid and ask
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="iSymbolID"> id of symbol to load  </param>
  /// <param name="oTime"> pointer to allocated instance of time_t to write time when this bid-ask pair was constructed on server </param>
  /// <param name="oBid"> pointer to allocated instance of double to write bid value  </param>
  /// <param name="oAsk"> pointer to allocated instance of double to write ask value  </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_GetPrices(SunkTCPClient* ipClient, int iSymbolId, time_t* oTime, double* oBid, double* oAsk);


  /// <summary>
  /// Send order
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="iInfo "> pointer to order info instance  </param>
  /// <param name="oTiker "> pointer to allocated int instance with id of registered order. </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_OpenOrder(SunkTCPClient* ipClient, MT4SendOrderInfo* iInfo, int* oTiker);

  /// <summary>
  /// Close order
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="Ticket"> Id of order to close  </param>
  /// <param name="Price"> price for close</param>
  /// <param name="Slippage"> maximum of allowed different bettwen your price and real market price </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_CloseOrder(SunkTCPClient* ipClient, int Ticket, double Price, int Slippage);

  /// <summary>
  /// Delete order 
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="Ticket"> Id of order to delete </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_DeleteOrder(SunkTCPClient* ipClient, int iTicket);


  /// <summary>
  /// Modify order
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="Ticket"> Id of order to modify </param>
  /// <param name="Price"> iNew order price</param>
  /// <param name="StopLoss"> new stop loss </param>
  /// <param name="TakeProfit"> new take profit  </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_ModifyOrder(SunkTCPClient* ipClient, int Ticket, double Price, double StopLoss, double TakeProfit);

  /// <summary>
  /// Get count of orders 
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="oCount"> pointer to allocated int instance for write count of orders  </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_GetNumberOrders(SunkTCPClient* ipClient, int* oCount);

  /// <summary>
  /// Get all orders
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="opArray"> pointer to allocated array of MT4OrderInfo items to write recived data.  </param>
  /// <param name="opArraySize"> size of allocated opArray. After call  return count of fulled items </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_GetOrders(SunkTCPClient* ipClient, MT4OrderInfo* opArray, int* opArraySize);

  /// <summary>
  /// Get order
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="iTiket"> id of order </param>
  /// <param name="oInfo"> pointer to allocated instance of MT4OrderInfo to write data </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_GetOrder(SunkTCPClient* ipClient, int iTiket, MT4OrderInfo* oInfo); 

  /// <summary>
  /// Get closed order count
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="oCount"> pointer to allocated int instance for write order count </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_GetNumberClosedOrders(SunkTCPClient* ipClient, int* oCount);

  /// <summary>
  /// Get closed orders
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="opArray"> pointer to allocated array of MT4ClosedOrderInfo items to write recived data.  </param>
  /// <param name="opArraySize"> size of allocated opArray. After call return count of fulled items </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_GetClosedOrders(SunkTCPClient* ipClient, MT4ClosedOrderInfo* opArray, int* oArraySize);

  /// <summary>
  /// Get closed order
  /// </summary>
  /// <param name="ipClient"> pointer to client instance </param>
  /// <param name="iTiket"> id of order </param>
  /// <param name="oInfo"> pointer to allocated instance of MT4ClosedOrderInfo for write data </param>
	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_GetClosedOrder(SunkTCPClient* ipClient, int iTiket , MT4ClosedOrderInfo* oInfo);

  /// <summary>
  /// Convert return code to text
  /// </summary>
	DLL_FUNC	TCHAR *		    __stdcall MT4_TC_GetErrorDescription( MT4_RET_CODE );


  // service functions 
  DLL_FUNC	DWORD			    __stdcall MT4_TC_GetMaxTimeout( void );

  DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TestTransport();

  DLL_FUNC  BOOL          __stdcall MT4_TC_StartServer(int iOnPort, char* LogFileName );

	DLL_FUNC	MT4_RET_CODE	__stdcall MT4_TC_StopServer(void);

#endif
/*----------------------------------------------------------------------*/