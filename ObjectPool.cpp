#include <string>
#include <iostream>
#include <list>

class Resource
{
    int value;

    public:
        Resource()
        {
            value = 0;
        }

        void reset()
        {
            value = 0;
        }

        int getValue()
        {
            return value;
        }

        void setValue(int number)
        {
            value = number;
        }
};

/* Note, that this class is a singleton. */
class ObjectPool
{
    private:
        std::list<Resource*> resources;
        
        static ObjectPool* instance;
        ObjectPool() {}
        
    public:    
        ~ObjectPool()
        {
            std::cout << "Total objs are " << resources.size() << std::endl;
            while(resources.size())
            {
                Resource *obj = resources.front();
                resources.pop_front();
                std::cout << "Deleting Resource at " << obj << std::endl;
                delete obj;
            }
        }


    public:
        /**
         * Static method for accessing class instance.
         * Part of Singleton design pattern.
         *
         * @return ObjectPool instance.
         */
        static ObjectPool* getInstance()
        {
            if (instance == 0)
            {
                instance = new ObjectPool;
            }
            return instance;
        }

        /**
         * Returns instance of Resource.
         * 
         * New resource will be created if all the resources
         * were used at the time of the request.
         *
         * @return Resource instance.
         */
        Resource* getResource()
        {
            if (resources.empty())
            {
                Resource* nR = new Resource;
                std::cout << "Creating new Resource at " << nR << std::endl;
                
                return nR;
            }
            else
            {
                Resource* resource = resources.front();
                std::cout << "Reusing existing Resource at " << resource << std::endl;
                resources.pop_front();
                return resource;
            }
        }

        /**
         * Return resource back to the pool.
         *
         * The resource must be initialized back to
         * the default settings before someone else
         * attempts to use it.
         *
         * @param object Resource instance.
         * @return void
         */
        void returnResource(Resource* object)
        {
            object->reset();
            resources.push_back(object);
        }
};

ObjectPool* ObjectPool::instance = 0;


int main()
{
    ObjectPool* pool = ObjectPool::getInstance();
    Resource* one;
    Resource* two;

    /* Resources will be created. */
    one = pool->getResource();
    one->setValue(10);
    std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;

    two = pool->getResource();
    two->setValue(20);
    std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;

    pool->returnResource(one);
    pool->returnResource(two);

    /* Resources will be reused. 
     * Notice that the value of both resources were reset back to zero.
     */
    one = pool->getResource();
    std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;

    two = pool->getResource();
    std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;
    
    pool->returnResource(one);
    pool->returnResource(two);
    delete pool;
   
    return 0;
}