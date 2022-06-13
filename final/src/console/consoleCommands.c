// ConsoleCommands.c
// This is where you add commands:
//		1. Add a protoype
//			static eCommandResult_T ConsoleCommandVer(const char buffer[]);
//		2. Add the command to mConsoleCommandTable
//		    {"ver", &ConsoleCommandVer, HELP("Get the version string")},
//		3. Implement the function, using ConsoleReceiveParam<Type> to get the parameters from the buffer.

#include <string.h>
#include "consoleCommands.h"
#include "console.h"
#include "consoleIo.h"
#include "draw.h"
#include "version.h"

#define IGNORE_UNUSED_VARIABLE(x)     if ( &x == &x ) {}

static eCommandResult_T ConsoleCommandComment(const char buffer[]);
static eCommandResult_T ConsoleCommandVer(const char buffer[]);
static eCommandResult_T ConsoleCommandHelp(const char buffer[]);
static eCommandResult_T ConsoleCommandParamExampleInt16(const char buffer[]);
static eCommandResult_T ConsoleCommandParamExampleHexUint16(const char buffer[]);
static eCommandResult_T ConsoleCommandFillScreenUint16(const char buffer[]);
static eCommandResult_T ConsoleCommandGetCursor(const char buffer[]);
static eCommandResult_T ConsoleCommandSetCursorX(const char buffer[]);
static eCommandResult_T ConsoleCommandSetCursorY(const char buffer[]);
static eCommandResult_T ConsoleCommandDrawPixel(const char buffer[]);
static eCommandResult_T ConsoleCommandGetColor(const char buffer[]);
static eCommandResult_T ConsoleCommandNextColor(const char buffer[]);
static eCommandResult_T ConsoleCommandFillScreenCurrent(const char buffer[]);


static const sConsoleCommandTable_T mConsoleCommandTable[] =
{
	{";", &ConsoleCommandComment, HELP("Comment! You do need a space after the semicolon. ")},
	{"help", &ConsoleCommandHelp, HELP("Lists the commands available")},
	{"ver", &ConsoleCommandVer, HELP("Get the version string")},
	{"int", &ConsoleCommandParamExampleInt16, HELP("How to get a signed int16 from params list: int -321")},
	{"u16h", &ConsoleCommandParamExampleHexUint16, HELP("How to get a hex u16 from the params list: u16h aB12")},
	{"fill", &ConsoleCommandFillScreenUint16, HELP("Fills the screen with a u16")},
	{"getcursor", &ConsoleCommandGetCursor, HELP("Returns the drawing cursor position")},
	{"setcursorx", &ConsoleCommandSetCursorX, HELP("Sets the x cursor position")},
	{"setcursory", &ConsoleCommandSetCursorY, HELP("Sets the y cursor position")},
	{"drawpixel", &ConsoleCommandDrawPixel, HELP("Draws a pixel on the screen at the set cursor location")},
	{"getcolor", &ConsoleCommandGetColor, HELP("Gets the u16 value of the colour to draw")},
	{"bucket", &ConsoleCommandFillScreenCurrent, HELP("Fill the screen with current colour")},
	{"nextcolor", &ConsoleCommandNextColor, HELP("Cycle to next colour")},

	CONSOLE_COMMAND_TABLE_END // must be LAST
};

static eCommandResult_T ConsoleCommandComment(const char buffer[])
{
	// do nothing
	IGNORE_UNUSED_VARIABLE(buffer);
	return COMMAND_SUCCESS;
}

static eCommandResult_T ConsoleCommandHelp(const char buffer[])
{
	uint32_t i;
	uint32_t tableLength;
	eCommandResult_T result = COMMAND_SUCCESS;

	IGNORE_UNUSED_VARIABLE(buffer);

	tableLength = sizeof(mConsoleCommandTable) / sizeof(mConsoleCommandTable[0]);
	for ( i = 0u ; i < tableLength - 1u ; i++ )
	{
		ConsoleIoSendString(mConsoleCommandTable[i].name);
#if CONSOLE_COMMAND_MAX_HELP_LENGTH > 0
		ConsoleIoSendString(" : ");
		ConsoleIoSendString(mConsoleCommandTable[i].help);
#endif // CONSOLE_COMMAND_MAX_HELP_LENGTH > 0
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}

static eCommandResult_T ConsoleCommandParamExampleInt16(const char buffer[])
{
	int16_t parameterInt;
	eCommandResult_T result;
	result = ConsoleReceiveParamInt16(buffer, 1, &parameterInt);
	if ( COMMAND_SUCCESS == result )
	{
		ConsoleIoSendString("Parameter is ");
		ConsoleSendParamInt16(parameterInt);
		ConsoleIoSendString(" (0x");
		ConsoleSendParamHexUint16((uint16_t)parameterInt);
		ConsoleIoSendString(")");
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}
static eCommandResult_T ConsoleCommandParamExampleHexUint16(const char buffer[])
{
	uint16_t parameterUint16;
	eCommandResult_T result;
	result = ConsoleReceiveParamHexUint16(buffer, 1, &parameterUint16);
	if ( COMMAND_SUCCESS == result )
	{
		ConsoleIoSendString("Parameter is 0x");
		ConsoleSendParamHexUint16(parameterUint16);
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}

static eCommandResult_T ConsoleCommandVer(const char buffer[])
{
	eCommandResult_T result = COMMAND_SUCCESS;

	IGNORE_UNUSED_VARIABLE(buffer);

	ConsoleIoSendString(VERSION_STRING);
	ConsoleIoSendString(STR_ENDLINE);
	return result;
}


const sConsoleCommandTable_T* ConsoleCommandsGetTable(void)
{
	return (mConsoleCommandTable);
}


static eCommandResult_T ConsoleCommandFillScreenUint16(const char buffer[])
{
	uint16_t parameterUint16;
	eCommandResult_T result;
	result = ConsoleReceiveParamHexUint16(buffer, 1, &parameterUint16);
	if ( COMMAND_SUCCESS == result )
	{
		ConsoleIoSendString("Updating screen with 0x");
		ConsoleSendParamHexUint16(parameterUint16);
		fillScreenWithColour(parameterUint16);
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}

static eCommandResult_T ConsoleCommandGetCursor(const char buffer[]) {
	eCommandResult_T result = COMMAND_SUCCESS;
	IGNORE_UNUSED_VARIABLE(buffer);

	ConsoleIoSendString("Cursor X is ");
	ConsoleSendParamInt16(getCursorX());
	ConsoleIoSendString(" Cursor Y is ");
	ConsoleSendParamInt16(getCursorY());
	ConsoleIoSendString(STR_ENDLINE);
	return result;
}

static eCommandResult_T ConsoleCommandSetCursorX(const char buffer[])
{
    int16_t parameterInt;
    eCommandResult_T result;
    result = ConsoleReceiveParamInt16(buffer, 1, &parameterInt);
    if ( COMMAND_SUCCESS == result )
    {
        setCursorX(parameterInt);
        ConsoleIoSendString("Parameter is ");
        ConsoleSendParamInt16(parameterInt);
        ConsoleIoSendString(" cursor x set to ");
        ConsoleSendParamInt16(getCursorX());
        ConsoleIoSendString(STR_ENDLINE);
    }
    return result;
}

static eCommandResult_T ConsoleCommandSetCursorY(const char buffer[])
{
    int16_t parameterInt;
    eCommandResult_T result;
    result = ConsoleReceiveParamInt16(buffer, 1, &parameterInt);
    if ( COMMAND_SUCCESS == result )
    {
        setCursorY(parameterInt);
        ConsoleIoSendString("Parameter is ");
        ConsoleSendParamInt16(parameterInt);
        ConsoleIoSendString(" cursor y set to ");
        ConsoleSendParamInt16(getCursorY());
        ConsoleIoSendString(STR_ENDLINE);
    }
    return result;
}

static eCommandResult_T ConsoleCommandDrawPixel(const char buffer[]) {
    eCommandResult_T result = COMMAND_SUCCESS;
    IGNORE_UNUSED_VARIABLE(buffer);

    ConsoleIoSendString("Drawing 0x");
    ConsoleSendParamHexUint16(getColorValue());
    ConsoleIoSendString(" at X: ");
    ConsoleSendParamInt16(getCursorX());
    ConsoleIoSendString(" Y: ");
    ConsoleSendParamInt16(getCursorY());
    drawPixel();
    ConsoleIoSendString(STR_ENDLINE);
    return result;
}

static eCommandResult_T ConsoleCommandGetColor(const char buffer[]) {
    eCommandResult_T result = COMMAND_SUCCESS;
    IGNORE_UNUSED_VARIABLE(buffer);

    ConsoleIoSendString("The current value to draw is 0x");
    ConsoleSendParamHexUint16(getColorValue());
    ConsoleIoSendString(STR_ENDLINE);
    return result;
}

static eCommandResult_T ConsoleCommandFillScreenCurrent(const char buffer[])
{
    eCommandResult_T result = COMMAND_SUCCESS;
    IGNORE_UNUSED_VARIABLE(buffer);
    if ( COMMAND_SUCCESS == result )
    {
        ConsoleIoSendString("Updating screen with 0x");
        ConsoleSendParamHexUint16(getColorValue());
        fillScreen();
        ConsoleIoSendString(STR_ENDLINE);
    }
    return result;
}

static eCommandResult_T ConsoleCommandNextColor(const char buffer[]) {
    eCommandResult_T result = COMMAND_SUCCESS;
    IGNORE_UNUSED_VARIABLE(buffer);

    nextColor();

    ConsoleIoSendString("The current value to draw is 0x");
    ConsoleSendParamHexUint16(getColorValue());
    ConsoleIoSendString(STR_ENDLINE);
    return result;
}
