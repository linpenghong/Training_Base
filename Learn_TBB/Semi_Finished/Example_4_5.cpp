class MyBuffer
{
    private:

        static const size_t buffer_size = 10000;

        char* my_end;

        // storage[0] holds the last character of the preceding buffer
        char storage[1 + buffer_size];

    public:
        
        // Pointer to first character in the buffer
        char* begin()
        {
            return storage + 1;
        }

        // Pointer to last character in the buffer
        char* end() const
        {
            return my_end;
        }

        // set end of the buffer
        void set_end(char* new_ptr)
        {
            my_end = new_ptr;
        }

        // number of bytes a buffer can hold
        size_t max_size() const
        {
            return buffer_size;
        }

        // number of bytes in buffer
        size_t size() const
        {
           return my_end - begin();
        } 
};

// Below is the top-level code for building and running the pipeline

tbb:pipeline pipeline;

// Create file-reading stage and add it to the pipeline
MyInputFilter input_filter(input_file);
pipeline.add_filter(input_filter);

// Create capitalization stage and add it to the pipeline
MyTransformFilter transform_filter;
pipeline.add_filter(transform_filter);

// Create file-writing stage and add it to the pipeline
MyOutputFilter output_filter(output_file);
pipeline.add_filter(output_filter);

// Run the pipeline
pipeline.run(MyInputFilter::n_buffer);

// Remove filters from pipeline before they are implicitly destroyed
pipeline.clear();
