IF NOT EXIST ..\DemoEngine\extern_libs\Procedutex\ (MKDIR ..\DemoEngine\extern_libs\Procedutex\lib\ | MKDIR ..\DemoEngine\extern_libs\Procedutex\include\procedutex\elements\ | MKDIR ..\DemoEngine\extern_libs\Procedutex\include\procedutex\math\ | MKDIR ..\DemoEngine\extern_libs\Procedutex\include\procedutex\random\ | MKDIR ..\DemoEngine\extern_libs\Procedutex\include\procedutex\types\ | MKDIR ..\DemoEngine\extern_libs\Procedutex\include\procedutex\utilities\)
copy .\ProcedutexLib\lib\*.lib /B ..\DemoEngine\extern_libs\Procedutex\lib\. /Y
copy .\ProcedutexLib\lib\*.pdb /B ..\DemoEngine\extern_libs\Procedutex\lib\. /Y
copy .\ProcedutexLib\inc\procedutex\elements\*.h ..\DemoEngine\extern_libs\Procedutex\include\procedutex\elements\. /Y
copy .\ProcedutexLib\inc\procedutex\math\*.h ..\DemoEngine\extern_libs\Procedutex\include\procedutex\math\. /Y
copy .\ProcedutexLib\inc\procedutex\random\*.h ..\DemoEngine\extern_libs\Procedutex\include\procedutex\random\. /Y
copy .\ProcedutexLib\inc\procedutex\types\*.h ..\DemoEngine\extern_libs\Procedutex\include\procedutex\types\. /Y
copy .\ProcedutexLib\inc\procedutex\utilities\*.h ..\DemoEngine\extern_libs\Procedutex\include\procedutex\utilities\. /Y