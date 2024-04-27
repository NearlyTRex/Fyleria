@ECHO OFF

@REM Possible paths for vcvars
SET VCVARS_COMMUNITY_2022="C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvars64.bat"
SET VCVARS_ENTERPRISE_2022="C:\\Program Files\\Microsoft Visual Studio\\2022\\Enterprise\\VC\\Auxiliary\\Build\\vcvars64.bat"
SET VCVARS_PROFESSIONAL_2022="C:\\Program Files\\Microsoft Visual Studio\\2022\\Professional\\VC\\Auxiliary\\Build\\vcvars64.bat"

@REM Activate first found
IF EXIST %VCVARS_COMMUNITY_2022% (CALL %VCVARS_COMMUNITY_2022%)
IF EXIST %VCVARS_ENTERPRISE_2022% (CALL %VCVARS_ENTERPRISE_2022%)
IF EXIST %VCVARS_PROFESSIONAL_2022% (CALL %VCVARS_PROFESSIONAL_2022%)
