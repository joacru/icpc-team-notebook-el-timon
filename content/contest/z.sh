d=${1:0:1}
[ "$2" = create ] && { mkdir -p "$d"; cp -n template.cpp "$d/$1.cpp"; exit; }
g++ -DLOCAL -std=c++17 -D_GLIBCXX_DEBUG -Wall -Wextra -Wconversion -Wshadow -o "$d/$1" "$d/$1.cpp" || exit
[ "$2" = run ]  && exec "./$d/$1"
[ "$2" = test ] && for f in "$d"/*.in; do echo "$f"; "./$d/$1" < "$f"; echo ==========; done