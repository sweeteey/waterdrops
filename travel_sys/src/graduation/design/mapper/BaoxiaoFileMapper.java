package graduation.design.mapper;

import java.util.*;
import org.apache.ibatis.annotations.Param;
import graduation.design.model.BaoxiaoFile;

public interface BaoxiaoFileMapper {

	public void insertObject(BaoxiaoFile baoxiaoFile);

	public void deleteObject(int id);

	public void updateObject(BaoxiaoFile baoxiaoFile);

	public BaoxiaoFile selectObject(int id);

	public List<BaoxiaoFile> getObjectList(@Param("field") String field,
										   @Param("fieldValue") String fieldValue);

}
