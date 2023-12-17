Pytania
• Jakie operacje są relatywnie szybko wykonywane na drzewie BST, porównaj złożoności czasowe
z innymi strukturami danych.
Drzewa BST (Binary Search Tree) są efektywne w wykonywaniu pewnych operacji, ale ich wydajność może być zależna od konkretnego układu drzewa. Oto kilka operacji, które są relatywnie szybko wykonywane na drzewie BST:

    Wstawianie (Insertion):
        Średnia złożoność czasowa: O(log n)
        Najgorsza złożoność czasowa: O(n) (w przypadku degeneracji drzewa do listy)

    Wyszukiwanie (Search):
        Średnia złożoność czasowa: O(log n)
        Najgorsza złożoność czasowa: O(n) (w przypadku degeneracji drzewa do listy)

    Usuwanie (Deletion):
        Średnia złożoność czasowa: O(log n)
        Najgorsza złożoność czasowa: O(n) (w przypadku degeneracji drzewa do listy)

• Na czym polega iteracyjne przechodzenie drzewa bez użycia rekurencji?

    Iteracyjne przechodzenie drzewa bez użycia rekurencji polega na wykorzystaniu stosu w celu przechowywania
    odwiedzonych juz node.

• W jaki sposób można użyć drzewo BST do sortowania elementów? Wskaż podobieństwo do
wcześniej poznanego algorytmu sortowania. Omów wady takiego rozwiązania.

    Przechodzimy przez drzewo w porządku in-order (lewy-pierwszy-środkowy-prawy), co pozwala na uzyskanie posortowanej sekwencji.
• Na czym polega przechodzenie drzewa preorder?
Przchodzenie w inorder polega na odwiedzeniu wezlow drzewa zaczynajac od jego korzenia w kolejnosci  root, lewe poddrzewo, prawe poddrzewo

• Na czym polega przechodzenie drzewa inorder? Jaka będzie kolejność wypisywanych elemen-
tów?

    Elementy zostana wypisane od najmniejszego do najwiekszego.
    Przchodzenie w inorder polega na odwiedzeniu wezlow drzewa zaczynajac od jego korzenia w kolejnosci lewe poddrzewo, root, prawe poddrzewo
• Na czym polega przechodzenie drzewa postorder,

    Przchodzenie w postorder polega na odwiedzeniu wezlow drzewa zaczynajac od jego korzenia w kolejnosci lewe poddrzewo, prawe poddrzewo, root
