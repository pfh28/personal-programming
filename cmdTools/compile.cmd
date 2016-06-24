@ECHO OFF
set filename=%1
echo %filename%

IF NOT %filename:.c=%==%filename% (
	gcc %filename% -o %filename:.c=.exe%
)
IF NOT %filename:.java=%==%filename% (
	javac %filename%
)