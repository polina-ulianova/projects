namespace student {
	class string {
		char*
			_data;
		unsigned int _size;
		static const unsigned int npos = -1;
	public:
		~string();
		string();
		string(unsigned int count, char ch);
		string(const char* other, unsigned int count);
		string(const char* other);
		string(const string& other);
		string(string&& other);
		string&
			operator= (const string& other);
		string&
			operator= (string&& other);
		string&
			operator= (const char* other);
		char&
			operator[](unsigned int pos);
		const char&
			operator[](unsigned int pos) const;
		const char*
			data() const;
		bool
			empty();
		unsigned int
			size() const;
		void
			clear();
		void
			push_back(char ch);
		void
			pop_back();
		string&
			append(const char* other, unsigned int count);
		string&
			append(const string& other);
		string&
			append(unsigned int count, const char& ch);
		string
			substr(unsigned int pos = 0, unsigned int count = npos);
	};
	template <typename T>
	class vector {
		T*
			_data;
		unsigned int _size;
	public:
		~vector();
		vector();
		vector(const vector& other);
		vector(vector&& other);
		explicit vector(unsigned int count, const T& val = T());
		explicit vector(unsigned int count);
		T&
			operator[] (unsigned int pos);
		const T& operator[] (unsigned int pos) const;
		T*
			data();
		const T* data() const;
		bool
			empty() const;
		void
			clear();
		void
			push_back(const T& value);
		void
			push_back(T&& value);
		void
			pop_back();
		void
			insert(unsigned int pos, unsigned int count, const T& value);
	};
}
