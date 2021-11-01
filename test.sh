while true
do
ARG=$(python3 -c "import random;print(\" \".join(str(x) for x in random.sample(range(1000), 500)))"); ./push_swap $ARG | ./checker $ARG
done