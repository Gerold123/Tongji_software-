#coding:utf-8
from array import*
from random import randint
import time
result=0
real_result=0
value=[]
answers=[]
i=0
j=0
count=0
flag=1
start=time.time()
num_questions=0
for _ in range(50):
	value.append(randint(0,100))
while num_questions<10:
	if(flag!=1):
		exit()
	start=time.time()
	if value[0]%2==0:
		result=input("the number {} question:{}+{}-{}*{}+{}=\n".format(num_questions+1,value[count],value[count+1],value[count+2],value[count+3],value[count+4]))
		try:
			result=int(result)
			real_result=value[count]+value[count+1]-value[count+2]*value[count+3]+value[count+4]
			real_result=int(real_result)
			message="{}+{}-{}*{}+{}={}".format(value[count+0],value[count+1],value[count+2],value[count+3],value[count+4],real_result)
			if result!=real_result:
				answers.append(message)
			else:
				i=i+1
		except ValueError:
				real_result=value[count+0]+value[count+1]-value[count+2]*value[count+3]+value[count+4]
				message="{}+{}-{}*{}+{}={}".format(value[count+0],value[count+1],value[count+2],value[count+3],value[count+4],real_result)
				answers.append(message)

	else:
		if value[1]!=0:
			result=input("the number {} question:{}/{}*{}+{}=\n".format(num_questions+1,value[count+0],value[count+1],value[count+2],value[count+3]))
			try:
				result=int(result)
				real_result=value[count+0]/value[count+1]*value[count+2]+value[count+3]
				real_result=int(real_result)
				message="{}/{}*{}+{}={}\n".format(value[count+0],value[count+1],value[count+2],value[count+3],real_result)
				if result!=real_result:
					answers.append(message)
				else:
					i=i+1
			except ValueError:
				real_result=value[0]/value[1]*value[2]+value[3]
				message="{}/{}*{}+{}={}\n".format(value[count+0],value[count+1],value[count+2],value[count+3],real_result)
				answers.append(message)

		else:
			result=input("the number {} question:{}-{}*{}=\n".format(num_questions+1,value[count+0],value[count+1],value[count+2]))
			try:
				result=int(result)
				real_result=value[count+0]-value[count+1]*value[count+2]
				real_result=int(real_result)
				message="{}-{}*{}={}".format(value[count+0],value[count+1],value[count+2],real_result)
				if result!=real_result:
					answers.append(message)
				else:
					i=i+1
			except ValueError:
				real_result=value[0]-value[count+1]*value[count+2]
				message="{}-{}*{}={}".format(value[count+0],value[count+1],value[count+2],real_result)
				answers.append(message)
	count=count+5
	print("\n")
	num_questions=num_questions+1
	if num_questions==10:
		end=time.time()
		print("Total time:{}\nthe number of correct answers:{}\n".format(end-start,i))
		print("the following are the right answers of the questions you got wrong:\n")
		for _ in range(10-i):
			print("{}".format(answers[j]))
			j=j+1
		flag=input("\nwhether to proceed to the next round of testing? please input:\n 1.proceed\n 2.exit\n")
		flag=int(flag)
		num_questions=0
		count=0
		if flag==1:
			value.clear()
			for _ in range(50):
				value.append(randint(0,100))


