package graduation.design.mapper;

import java.util.*;
import org.apache.ibatis.annotations.Param;
import graduation.design.model.BaoxiaoType;

public interface BaoxiaoTypeMapper {

	public void insertObject(BaoxiaoType baoxiaoType);

	public void deleteObject(int id);

	public void updateObject(BaoxiaoType baoxiaoType);

	public BaoxiaoType selectObject(int id);

	public List<BaoxiaoType> getObjectList(@Param("field") String field,
			@Param("fieldValue") String fieldValue);

}
