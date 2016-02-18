# -*- coding: utf-8 -*-
"""
Created on Sat Jan 23

@author: ramsakhamuri
"""
from pyclustering.cluster.birch import birch
import os
import time
import shutil
import subprocess
############### Configure the below variables for a change in system #################
PROJECT='/root/Desktop/ram/'
HADOOP_HOME='/user/root/in/'
#####################################################################################

PROC_DIR= PROJECT + 'PROJECT/BIRCH_PROCESS/'
HADOOP_PROC_DIR= PROJECT + 'PROJECT/HADOOP_PROCESS/'
PROCESSED_DIR= PROJECT + 'PROJECT/PROCESSED/'
LOGDIR=  PROJECT + 'PROJECT/LOGDIR/logfile'
birch1=birch([[]],10,[],initial_diameter=10)
z=0
while True :   
    while (os.listdir(PROC_DIR)==[]):
        time.sleep(30)
    for datefile in os.listdir(PROC_DIR):
        DATE=datefile
    HADOOP_PATH= HADOOP_HOME + DATE
    os.popen("touch "+HADOOP_PROC_DIR + "DONE")
    #Below loop is to check moving of files from Hadoop dir to Birch Dir is finished    
    while(os.path.isfile(PROC_DIR+datefile) == True):
        time.sleep(10)
    DONEFILE=PROC_DIR+"DONE"
    os.remove(DONEFILE)
    d1={}
    #d2=[]
    d2=os.listdir(PROC_DIR)
    l=[]
    c=0
    d=0
    p = subprocess.Popen(["hadoop","fsck",HADOOP_PATH,"-files","-blocks","-locations"], stdout=subprocess.PIPE)
    (output,error)=p.communicate()
    for x in str(output)[2:len(output)-3].split('\\n'):
        if d<len(d2):
            for y in d2:
                if y in x:
                    d1[y]=c
                    d=d+1
        l.append(x)
        c=c+1
    
    for file in d2:
        address=[]
        data=l[d1[file]+1:l[d1[file]+1:].index('')+d1[file]+1]
        for line in data:
            address+=line[line.index('[')+1:line.index(']')].replace(' ','').split(',')
        address=list(set(address))
        d1[file]=address
    
    for birch_file in d2:
        data=[]
        file=''
        file=PROC_DIR+birch_file
        for i in open(file,'r').readlines():
            k=i.strip().split()
            for j in range(0,len(k)):
                k[j]=float(k[j])
            #k=k[2:]
            data.append(k)
        birch1._birch__pointer_data=data;
        birch1._birch__hadoop_address=d1[birch_file]
        birch1.process()
    for file2 in d2:
        file2=PROC_DIR+"/"+file2
        shutil.move(file2,PROCESSED_DIR)
    file_out= LOGDIR +str(z)+'.txt'
    f1=open(file_out,'w')
    f1.write(str(d2))
    f1.write("CF Tree after the previous load")
    f1.write("\n")
    f1.write(str(birch1._birch__tree.leafes))
    f1.close()
    z=z+1
