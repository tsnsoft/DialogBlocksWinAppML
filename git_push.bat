@echo off
@сhср 65001

cd /d "%~dp0"

echo Добавление всех изменений...
git add .

for /f "tokens=2 delims==." %%I in ('wmic os get localdatetime /value') do set datetime=%%I
set commit_msg=update_%datetime%

echo Создание коммита...
git commit -m "%commit_msg%"

echo Отправка на GitHub...
git push origin main

echo Готово!
pause
