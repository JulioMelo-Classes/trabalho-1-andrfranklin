#ifndef Aposta_hpp
#define Aposta_hpp

#include<vector>

class Aposta{
	private:
		double credit;
		int rounds;
		std::vector<int> spots;

	public:
		Aposta();
		Aposta(double credit_, int rounds_, std::vector<int> spots_);
		double get_credits();
		void set_plus_credit(double value_);
		void set_less_credit(double value_);
		int get_rounds();
		std::vector<int> get_spots();
		
};


#endif