class List {
	public:
	virtual void add(int num) = 0;
	virtual int get(int pos) = 0;
	virtual int remove(int num) = 0;
	virtual void print() = 0;
	virtual void removeFirst() = 0;
	virtual void removeLast() = 0;
	virtual int removeAt(int pos) = 0;
	virtual int removeAll(int num) = 0;
	virtual int addAt(int num, int pos) = 0;
	virtual int retain(int num) = 0;
};