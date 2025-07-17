## Class-diagram

Admin і RegisteredUser наслідуються в User
Rental як і Purchase залежить від юзера, без якого не зможуть ббути виконані(ніхто нічого не купить або не орендує)
Так само PaymentMethod залежить від Rental і Purchase.
Rental в свою чергу асоціюється з Movie, а Purchase має в собі Movie, яке може існувати і без покупки. Так само як і Genre може існувати, якщо він не відноситься до певного кіно.
Review завжди має бути про якесь кіно і не існує без нього.

## State-rental

Додав Non-active замість Created. Це дає змогу переходити в режим такого собі очікування що створює цикл.

## Use-case

Admin:
	manage content
	login
RegisteredUser:
	login
	purchase movie
	watch movie
	browse movies
	rent movie
Guest:
	brose movies
	watch movie
	purchase movie
	register

## Sequence-rent and Sequence-purchase

Обидві діаграми описують самі себе. Єдина різниця це в тому як Система не чекає, поки користувач натисне кнопку аби провірити чи він авторизований