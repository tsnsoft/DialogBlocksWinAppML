@echo off
@�h�� 65001

cd /d "%~dp0"

echo ���������� ���� ���������...
git add .

for /f "tokens=2 delims==." %%I in ('wmic os get localdatetime /value') do set datetime=%%I
set commit_msg=update_%datetime%

echo �������� �������...
git commit -m "%commit_msg%"

echo �������� �� GitHub...
git push origin main

echo ������!
pause
