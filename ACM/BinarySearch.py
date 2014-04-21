import sys

def Bsearch(array,head,tail,target):
	mid = (head+tail)/2
	if head>tail:
		print False
		return -1
	if array[mid] == target :
		print mid
	elif array[mid] < target :
		Bsearch(array,mid+1,tail,target)
	elif array[mid] > target :
		Bsearch(array,head,mid-1,target)

def BinarySearch(array,target):
	n=len(array)
	head=0
	tail=n-1
	mid=n/2
	Bsearch(array,head,tail,target)

def main():
	array=[1,2,3,4,5,6,7,8,9]
	target=3
	print 'search for ',target,' it needs to be ',target-1
	BinarySearch(array,target)
	target=9
	print 'search for ',target,' it needs to be ',target-1
	BinarySearch(array,target)
	target=10
	print 'search for ',target,' it needs to be ',False
	BinarySearch(array,target)

if __name__=='__main__':
	main()
