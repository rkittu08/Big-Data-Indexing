1.This project is developed using Python 3.5. Please install 3.5 version of Python before actually starting anything else.

2.For installation of pyclustering into a specific system we need to configure its setup.py file accordingly.

3.Open setup.py in pyclustering and modify the value of url to the path of pyclustering folder in your file system.
		url = '~/Desktop/ram/pyclustering'

4.Install the pyclustering module into your system by executing following command in your unix terminal.

python3.5 setup.py install

5.Now install the Hadoop cluster on your machine by following the Setting-Up-Hadoop-Made-Easy.pdf

6.Open the following path in terminal /path/to/ram/folder/PROJECT/client_script/

7.Open client.py and client.sh and modify the path variables in the beginning of the programs accordingly.

8.open execution_script.sh in ram folder and modify the path of the scripts. 

########## To start the execution ##################
Execute the execution_script.sh from linux terminl.
bash execution_script.sh

############# order of execution sequence #######################
1. Place your input files in INPUT folder inside ram/PROJECT/
2. Files will be moved into HADOOP_PROCESS and gets processed.
3. Once gets processed into Hadoop they will be moved into BIRCH_PROCESS folder.
4. Once gets processed into Birch will be moved into processed folder.
5. Program places a new tree logfile into ram/PROJECT/LOGDIR folder for every processed file.

############ Possible failures and rectification method ###################
1. Program has two logfiles, one for client.py and the other for client.sh in ram/PROJECT/LOGDIR/
2. If any doubt of failure, execute the following command in unix terminal.
ps -ef | grep client.sh
ps -ef | grep client.py
3. Both of the above should return their own processes running if not returned for any, means it has failed.
4. Go to the logfile of the failed process, find the reason and rectify the error in the input data or if any other.
5. To rerun the entire process you have to kill the running process either client.sh or client.py.
6. Take the process id of running process from step 2 and execute the following
kill pid
7. Check the BIRCH_PROCESS and HADOOP_PROCESS folder and move the input files back to the INPUT directory and rerun the process again.
