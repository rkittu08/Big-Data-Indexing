#############################################################
# 	Author Ramakrishna created on Sat Jan 23	    #
#############################################################
PROJECT='/root/Desktop/ram/'
HADOOP_HOME='/user/root/in/'

IN_DIR=$PROJECT'PROJECT/INPUT'
HADOOP_PROC_DIR=$PROJECT'PROJECT/HADOOP_PROCESS'
BIRCH_PROC_DIR=$PROJECT'PROJECT/BIRCH_PROCESS'


while true
do
DATE=`date +%Y-%m-%d`
HADOOP_PATH=$HADOOP_HOME$DATE
if [[ $(ls $IN_DIR) != '' ]]
then
	while [[ $(ls $HADOOP_PROC_DIR) != '' ]]
	do
	sleep 10
	echo "previous files are still in Birch process directory "$HADOOP_PROC_DIR
	done

	mv $IN_DIR/* $HADOOP_PROC_DIR
	hadoop fs -ls $HADOOP_PATH  || hadoop fs -mkdir $HADOOP_PATH

	hadoop fs -copyFromLocal $HADOOP_PROC_DIR/* $HADOOP_PATH
	
	while [[ $(ls $BIRCH_PROC_DIR) != '' ]]
	do
	sleep 10
	echo "previous files are still in Birch process directory "$BIRCH_PROC_DIR
	done	
	
	touch $BIRCH_PROC_DIR/$DATE
	
	while [ ! -f $HADOOP_PROC_DIR"/DONE" ]
	do
	sleep 10
	done
	
	mv $HADOOP_PROC_DIR/* $BIRCH_PROC_DIR
	rm $BIRCH_PROC_DIR/$DATE
fi

sleep 60
done


