cd ..
cd dbScripts
for entry in `ls $dbScripts`; do
    echo Executing sql file -  $entry
	mysql -u root  automatedMT4 < $entry
	
done