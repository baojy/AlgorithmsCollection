import sys

def swap(array,a,b):
	temp=array[a]
	array[a]=array[b]
	array[b]=temp

def partition(array,head,tail):
	pivotops=head
	pivot=array[head]
	for index in range(head,tail+1):
		item=array[index]
		if item<pivot:
			pivotops+=1
			if pivotops!=index:
				swap(array,pivotops,index)
	swap(array,head,pivotops)
	return pivotops

def Qsort(array,head,tail):
	if head<tail:
		pivotops= partition(array,head,tail)
		Qsort(array,head,pivotops-1)
		Qsort(array,pivotops+1,tail)

def main():
	array=[2,1,4,3,6,5]
	print array
	Qsort(array,0,len(array)-1)
	print 'after Qsort ',array

if __name__=='__main__':
	main()
