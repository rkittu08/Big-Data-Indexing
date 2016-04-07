import h5py
import datetime as dt
import math as m

f=h5py.File('/root/Desktop/ram/0158631/test.hd5','r')

date=dt.datetime.today()
print(date)
#print(data[1][1])


#l=[]
#for x in data:
#    k=[]
#    for y in x:
#        k.append(y[1])    
#    l.append(k)
#print(l[1:10])
#print(len(l))

g=open("/root/Desktop/test3.txt",'a')
for x in ['grooves','helixpar','helixradius','inter','positions']:
    data=f.get(x)
    d=''
    for z in data:
        for k in range(1,len(z[0])):   
            c=1  
            l=''
            for y in z:

                l=l+str(0 if m.isnan(y[k]) else y[k])+('\n' if c==len(z) else '\t')
                c=c+1
                
            d+=l  
    g.write(d)
g.close()


print(dt.datetime.today())
print(dt.datetime.today()-date)
#l=l+str(float(0 if y[k]== b'---' else (0 if m.isnan(float(y[k])) else y[k])))+('\n' if c==len(z) else '\t')
#>>> runfile('/root/anaconda3/tests/untitled0.py', wdir='/root/anaconda3/tests')
#grooves 5
#helixpar 7
#helixradius 7
#inter 7
#intra 7
#positions 7
#tors1 8
#tors2 8
#2016-02-19 11:40:46.070827
#2016-02-19 11:41:10.888178
#0:00:24.817397
#>>> runfile('/root/Desktop/ram/PROJECT/client_script/test.py', wdir='/root/Desktop/ram/PROJECT/client_script')
#grooves
#helixpar
#helixradius
#inter
#intra
#positions
#tors1
#tors2
#2016-02-19 11:46:28.047871
#2016-02-19 11:47:07.846552
#0:00:39.798722