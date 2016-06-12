#!/bin/bash
Date=`date "+%Y-%m-%d %H:%M:%S"`
longitude=`awk -F , '{print $4}'   rmnull`
latitude=`awk -F , '{print $5}'   rmnull`
accuracy=`awk -F , '{print $6}'   rmnull`
position=`awk -F , '{print $14}'   rmnull`
echo $position
mysql -u root -plinkosky8890 <<EOF
use testDB;
insert into Position (name,time,longitude,latitude,accuracy,position) values('www','$Date','$longitude','$latitude','$accuracy','$position');
select*from Position;
EOF
