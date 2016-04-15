/*
**
**  File: modbus_low_level_functions.h
**
**
**  Implements the Following commands
**
*/

typedef uint16 (*read16)( unsigned current_index );
typedef void (*write16)( unsigned current_index, uint16 value );
typedef float (*read_float)( unsigned current_index );
typedef void (*write_float)(unsigned current_index, float value );
typedef unsigned (*fifo_number)( void );
typedef uint16 (*fifo_read)(unsigned current_index );




void assemble_function_3_read( unsigned out_buffer_size, char *output_buffer, unsigned byte_stream_number, char *byte_stream, read16, read16  function );
void assemble_function_16_write( unsigned out_buffer_size, char *output_buffer, unsigned byte_stream_number, char *byte_stream, write16 function );
void assemble_function_22_write( unsigned out_buffer_size, char *output_buffer, unsigned byte_stream_number, char *byte_stream, write_float function );
void assemble_function_23_read( unsigned out_buffer_size, char *output_buffer, unsigned byte_stream_number, char *byte_stream, read_float function );
void assemble_function_24_fifo( unsigned out_buffer_size, char *output_buffer, unsigned byte_stream_number, char *byte_stream,   fifo_number  function1,  fifo_read  function1 );


typedef struct
{
	int         start_register;
	read_16 access_function;
}message_3_str;


typedef struct
{
	int         start_register;
	write_16 access_function;
}message_16_str;

typedef struct
{
	int             start_register;
	write_float  access_function;
}message_22_str;


typedef struct
{
	int             start_register;
	read_float  access_function;
}message_23_str;

typedef struct
{
	int                start_register;
	fifo_number   number_function;
	fifor_read       fifo_function;
}message_24_str;



#if 0
    Backgound Documentation
    
/*
    Modbus Function Codes
    
03 Read Holding Registers 

Query

Slave Address 11
Function 03
Starting Address Hi 00
Starting Address Lo 6B
No. of Points Hi 00
No. of Points Lo 03
Error Check (LRC or CRC) ––

Slave Address 11
Function 03
Byte Count 06
Data 1  Hi  02
Data 1 Lo  2B
Data 2 Hi  00
Data 2 Lo  00
Data 3 Hi   00
Data 3 Lo  64
Error Check (LRC or CRC) ––

   16 (10 Hex) 
   
   Query 
   Field Name (Hex)
   Slave Address 11
  Function 10
  Starting Address Hi 00
  Starting Address Lo 01
  No. of Registers Hi 00
  No. of Registers Lo 02
  Byte Count 04
  Data Hi 00
  Data Lo 0A
  Data Hi 01
  Data Lo 02
  Error Check (LRC or CRC) ––.

Response
Slave Address 11
Function 10
Starting Address Hi 00
Starting Address Lo 01
No. of Registers Hi 00
No. of Registers Lo 02
Error Check (LRC or CRC) ––
 
 22 Write Float
    Query 
   Field Name (Hex)
   Slave Address 11
  Function 16
  Starting Address Hi 00
  Starting Address Lo 01
  No. of Registers Hi 00
  No. of Registers Lo 02
  Byte Count 04
  Data 1 MSB 00
  Data 1 3   00
  Data 1 2  00
  Data 1 LSB  0A
  Data 2 MSB 00
  Data 2 3   00
  Data 2 2  00
  Data 2 LSB  0A
  Error Check (LRC or CRC) ––.

 23 Read float
 
Slave Address 11
Function 17
Read Reference Address Hi 00
Read Reference Address Lo 04
Quantity to Read Hi 00
Quantity to Read Lo 06
Error Check (LRC or CRC) ––

Response
 
 Slave Address 11
Function 17
Byte Count 18
Read Data 1 4 MSB
Read Data 1 3 
Read Data 1 2
Read Data 1  LSB

........................
......................
Read Data 1 4 MSB
Read Data 1 3 
Read Data 1 2
Read Data 1  LSB


Error Check (LRC or CRC) –
 
 
 24 (18Hex) Read FIFO Queue

Input message

Slave Address 11
Function 18
FIFO Pointer Address Hi 04
FIFO Pointer Address Lo DE
Error Check (LRC or CRC) ––

Response

Slave Address 11
Function 18
Byte Count Hi 00
Byte Count Lo 08
FIFO Count Hi 00
FIFO Count Lo 03
FIFO Data Reg 1 Hi 01
FIFO Data Reg 1 Lo B8
FIFO Data Reg 2 Hi 12
FIFO Data Reg 2 Lo 84
FIFO Data Reg 3 Hi 13
FIFO Data Reg 3 Lo 22
Error Check (LRC or CRC) –



#endif