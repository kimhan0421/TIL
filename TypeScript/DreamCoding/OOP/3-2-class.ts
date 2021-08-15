{
	type CoffeeCup = {
		shots: number;
		hasMilk: boolean;
	};

	class CoffeeMaker {
		// class에서는 let, const, function을 명시하지 않아도 됨.
		// 멤버변수에 접근할 때는 this.으로 접근함
		// class에서는 constructor가 존재함
		BEANS_GTAMM_PER_SHOT: number = 7;

		coffeeBeans: number = 0;
		makeCoffee(shots: number): CoffeeCup {
			if (this.coffeeBeans < shots * this.BEANS_GTAMM_PER_SHOT) {
				throw new Error('Not enough coffee beans!');
			}
			this.coffeeBeans -= shots * this.BEANS_GTAMM_PER_SHOT;
			return {
				shots: shots,
				hasMilk: false,
			};
		}
	}

	coffeeBeans += 3 * BEANS_GTAMM_PER_SHOT;
	const coffee = makeCoffee(2);
	console.log(coffee);
}
