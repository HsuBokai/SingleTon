#ifndef _SINGLE_TON_H_
#define _SINGLE_TON_H_

#define MAKE_SINGLE_TON(T)			\
private:					\
	T();					\
	T(const T& s);				\
	T& operator = (const T& s);		\
	~T();					\
public:						\
	static T& instance(){			\
		static T _uniqueInstance;	\
		return _uniqueInstance;		\
	}					\

#endif
