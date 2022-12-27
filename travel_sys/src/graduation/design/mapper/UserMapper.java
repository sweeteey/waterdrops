package graduation.design.mapper;

import graduation.design.model.User;

import java.util.List;

import org.apache.ibatis.annotations.Param;

public interface UserMapper {

	public void insertObject(User user);

	public void deleteObject(int id);

	public void updateObject(User user);

	public User selectObject(int id);

	public User getObjectByName(User user);

	public List<User> getObjectList(@Param("field") String field,
			@Param("fieldValue") String fieldValue);

}
