class Image
{
    private:

        float* _data;

    public:

        Image(const int nColumn,
              const int nRow)
        {
            _data = new float[nColumn * nRow];
        }

        // opeator [] takes exactly one argument
        /***
        float& operator[](const int x, const int y)
        {
            return _data[y * nColumn * x];
        }
        ***/
};

int main()
{
    return 0;
}
